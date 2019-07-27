import shlex
import atexit
import itertools

always_flags = shlex.split("""
  -static-libstdc++ -std=c++17
""")
mini_flags = shlex.split("""
  -DWITH_SMART_PTR
  -fno-exceptions
  -fno-rtti
  -s
  -Os
  -fno-stack-protector
  -ffunction-sections
  -fdata-sections
  -Wl,--gc-sections
  -fno-unroll-loops
  -fmerge-all-constants
  -fno-ident
  -ffast-math
  -Wl,-z,norelro
  -Wl,--build-id=none
""")


mini_env = Environment(CCFLAGS=mini_flags + always_flags)
env = Environment(CCFLAGS=always_flags)
mini_env['BUILDERS']['Strip'] = Builder(action='strip $SFLAGS -o $TARGET $SOURCE')
mini_env['SFLAGS'] = shlex.split("""
  -S
  --strip-unneeded
  --remove-section=.note.gnu.gold-version
  --remove-section=.comment
  --remove-section=.note
  --remove-section=.note.gnu.build-id
  --remove-section=.note.ABI-tag
  --remove-section=.eh_frame
  --remove-section=.eh_frame_ptr
""")

mini = mini_env.Object(
  target='.build/mini-prog.o'
, source='mini.cpp')
prog = env.Object(
  target='.build/prog.o'
, source='mini.cpp')

mini = mini_env.Program(target='mini-prog.unstripped', source=mini)[0]
mini = mini_env.Strip(target='mini-prog', source=mini)[0]
prog = env.Program(target='prog', source=prog)[0]

all_progs = []
for i, flag in enumerate(mini_flags):
  flags = always_flags + [flag]
  obj = env.Object(target=f'.build/prog-{i}.o', source='mini.cpp', CCFLAGS=flags)
  p = env.Program(target=f'progs/prog-{i}.unstripped', source=obj)[0]
  setattr(p.attributes, 'theflag', flag)
  s = mini_env.Strip(target=f'progs/prog-{i}', source=p)[0]
  setattr(s.attributes, 'theflag', flag)
  all_progs.extend([p, s])

bins = [mini, prog] + all_progs
Default(bins)

@atexit.register
def comparebins():
  def lj(s,i=6):
    return f'{s}'.ljust(i)
  reg_data = open(prog.path, 'rb').read()
  min_data = open(mini.path, 'rb').read()
  reg_size = len(reg_data)
  min_size = len(min_data)
  reg_path = prog.path.ljust(26)
  min_path = mini.path.ljust(26)

  diff = min_size - reg_size

  print(f"{reg_path} > {lj(reg_size)}")
  print(f"{min_path} > {lj(min_size)}  ({lj(diff)}")

  for p in all_progs:
    p_data = open(p.path, 'rb').read()
    p_size = len(p_data)
    diff = p_size - reg_size
    print(f"{p.path.ljust(26)} > {lj(p_size)}  ({lj(diff)}) {p.attributes.theflag}")

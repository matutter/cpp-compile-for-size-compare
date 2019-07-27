Comparison of various flags & features.

```
prog                       > 94408 
mini-prog                  > 14040   (-80368
progs/prog-0.unstripped    > 110680  (16272 ) -DWITH_SMART_PTR
progs/prog-0               > 59192   (-35216) -DWITH_SMART_PTR
progs/prog-1.unstripped    > 93952   (-456  ) -fno-exceptions
progs/prog-1               > 50904   (-43504) -fno-exceptions
progs/prog-2.unstripped    > 94272   (-136  ) -fno-rtti
progs/prog-2               > 51000   (-43408) -fno-rtti
progs/prog-3.unstripped    > 94408   (0     ) -s
progs/prog-3               > 51000   (-43408) -s
progs/prog-4.unstripped    > 20352   (-74056) -Os
progs/prog-4               > 14136   (-80272) -Os
progs/prog-5.unstripped    > 94360   (-48   ) -fno-stack-protector
progs/prog-5               > 51000   (-43408) -fno-stack-protector
progs/prog-6.unstripped    > 94408   (0     ) -ffunction-sections
progs/prog-6               > 51000   (-43408) -ffunction-sections
progs/prog-7.unstripped    > 94408   (0     ) -fdata-sections
progs/prog-7               > 51000   (-43408) -fdata-sections
progs/prog-8.unstripped    > 94408   (0     ) -Wl,--gc-sections
progs/prog-8               > 51000   (-43408) -Wl,--gc-sections
progs/prog-9.unstripped    > 94408   (0     ) -fno-unroll-loops
progs/prog-9               > 51000   (-43408) -fno-unroll-loops
progs/prog-10.unstripped   > 94408   (0     ) -fmerge-all-constants
progs/prog-10              > 51000   (-43408) -fmerge-all-constants
progs/prog-11.unstripped   > 94408   (0     ) -fno-ident
progs/prog-11              > 51000   (-43408) -fno-ident
progs/prog-12.unstripped   > 94408   (0     ) -ffast-math
progs/prog-12              > 51000   (-43408) -ffast-math
progs/prog-13.unstripped   > 94408   (0     ) -Wl,-z,norelro
progs/prog-13              > 51000   (-43408) -Wl,-z,norelro
progs/prog-14.unstripped   > 94408   (0     ) -Wl,--build-id=none
progs/prog-14              > 51000   (-43408) -Wl,--build-id=none
```

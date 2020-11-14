import random
import shutil, path

fname = path.Path(__file__).stem
rint = lambda x, y: random.randint(x, y)

random.seed(0)
root = path.Path(f'{fname}_cases')
if not root.exists():
    root.mkdir()



cases = [
"""1000
1 0
0 1
""", 

"""3
1 2
3 4
""", 

"""0
1 -2
-3 4
""", 

"""1
1 -2
3 4
""", 

"""1000
1 -2
3 4
""", 

"""1000
999 1222
1289 1293
""", 


]

for _ in range(4):
    n = rint(1e8, 1e9)
    # n = rint(1e8, 1e18)
    a, b, c, d = rint(-1e4, 1e4), rint(-1e4, 1e4), rint(-1e4, 1e4), rint(-1e4, 1e4)
    s = f'{n}\n{a} {b}\n{c} {d}\n'
    cases.append(s)


for i, case in enumerate(cases):
    fin = open(root / f'case_{i+1:02}.in', 'w')
    fin.write(case)
    fin.close()


import subprocess
for i in range(10):
    fin = open(root / f'case_{i+1:02}.in', 'r')
    fout = open(root / f'case_{i+1:02}.out', 'w')
    exe = f"{fname}.exe"
    p  = subprocess.Popen(exe, stdin=fin, stdout=fout)
    p.wait(timeout=1)

# shutil.make_archive(fname, 'zip', base_dir=str(root))

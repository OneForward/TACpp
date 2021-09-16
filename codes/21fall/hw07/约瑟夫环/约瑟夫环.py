import random
import shutil, path

fname = path.Path(__file__).stem
rint = lambda x, y: random.randint(x, y)

random.seed(0)
root = path.Path(f'{fname}_cases')
if not root.exists():
    root.mkdir()

cases = []
for i in range(5):
    n = rint(1, 10)
    m = rint(1, n)
    cases.append(f'{n} {m}')
for i in range(5):
    n = rint(1, 1e4)
    m = rint(1, 1e8)
    cases.append(f'{n} {m}')

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

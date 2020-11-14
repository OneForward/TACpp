import random
import shutil, path

fname = path.Path(__file__).stem
rint = lambda x, y: random.randint(x, y)

random.seed(0)
root = path.Path(f'{fname}_cases')
if not root.exists():
    root.mkdir()

cases = ['']
for i in range(4):
    cases.append(' '.join( f'{x}' for x in random.choices(range(10), k=rint(0, 10)) ))

for i in range(5):
    cases.append(' '.join( f'{x}' for x in random.choices(range(1000), k=rint(0, 1000)) ))


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

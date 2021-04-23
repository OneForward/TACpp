import random
import shutil, path

fname = path.Path(__file__).stem
random.seed(0)
root = path.Path(f'{fname}_cases')
if not root.exists():
    root.mkdir()

Ns = [10, 100, 1000, 10000, 100000]
for i in range(10):
    s = ' '.join(f'{random.randint(1, Ns[i//5])}' for _ in range(4)) + ' '
    open(root / f'case_{i+1:02}.in', "w").write(s)

import subprocess
for i in range(10):
    fin = open(root / f'case_{i+1:02}.in', 'r')
    fout = open(root / f'case_{i+1:02}.out', 'w')
    exe = f"{fname}.exe"
    p  = subprocess.Popen(exe, stdin=fin, stdout=fout)
    p.wait(timeout=1)

# shutil.make_archive(fname, 'zip', base_dir=str(root))

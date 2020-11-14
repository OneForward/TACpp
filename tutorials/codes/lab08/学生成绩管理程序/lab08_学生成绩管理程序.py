# import random
import shutil, path
import names 
random = names.random

random.seed(0)

fname = path.Path(__file__).stem
root = path.Path(f'{fname}_cases')
if not root.exists():
    root.mkdir()

names_bank = [names.get_full_name() for _ in range(30)]

gen_grade = lambda: random.randint(0, 100)

gen_sid = lambda: f'520029910{random.randint(0, 999):03}' 
# gen_name = lambda: names.get_full_name()
gen_name = lambda: random.choice(names_bank)
gen_grades = lambda: f'{gen_grade()} {gen_grade()} {gen_grade()}'

students = {}
def insert():
    sid, sname = gen_sid(), gen_name()
    students[sid] = sname
    return f'1 {sid} {gen_grades()} {sname}'

update_ok = lambda: f'2 {random.choice(tuple(students.keys()))} {gen_grades()} {gen_name()}'
update_bad = lambda: f'2 {gen_sid()} {gen_grades()} {gen_name()}'
delete_ok = lambda: f'3 {random.choice(tuple(students.keys()))}'
delete_bad = lambda: f'3 {gen_sid()}'

search_by_sid_ok = lambda: f'4 {random.choice(tuple(students.keys()))}'
search_by_sid_bad = lambda: f'4 {gen_sid()}'
search_by_sname_ok = lambda: f'5 {random.choice(tuple(students.values()))}'
search_by_sname_bad = lambda: f'5 {gen_name()}'

display_by_sid = lambda:'6'
display_by_total_score = lambda:'7'

func_banks = [
    insert, update_ok, update_bad, delete_ok, delete_bad, 
    search_by_sid_ok, search_by_sid_bad, search_by_sname_ok, search_by_sname_bad,
    display_by_sid, display_by_total_score,
]


Ks = [10, 100, 1000]

weights = [10] + [1] * (len(func_banks) - 1)
for i in range(1, 10):
    k = Ks[i//(10//len(Ks) + 1)]
    s = '\n'.join( f() for f in random.choices( func_banks, k=k, weights=weights) )
    s += '\n6\n7\n0'
    open(root / f'case_{i+1:02}.in', "w").write(s)

open(root / f'case_01.in', "w").write(
"""
1 520021910437 99 100 98 Zhang San
1 520021910438 99 100 92 Zhang San
1 520021910439 90 100 94 Li Si
1 520021910440 90 100 94 Wang Wu
2 520021910437 89 100 94 Zhang San
3 520021910430
4 520021910437
5 Zhang San
6
7
0
"""
)

import subprocess
for i in range(10):
    fin = open(root / f'case_{i+1:02}.in', 'r')
    fout = open(root / f'case_{i+1:02}.out', 'w')
    exe = f"{fname}.exe"
    p  = subprocess.Popen(exe, stdin=fin, stdout=fout)
    p.wait(timeout=3)

# shutil.make_archive(fname, 'zip', base_dir=str(root))

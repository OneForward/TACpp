import pandas as pd 
import re 

f_canvas = 'canvas 直接导出（csv 模板信息）.csv'
f_educoder = 'educoder 直接导出（源分数信息）.xlsx'

# https://community.canvaslms.com/t5/Instructor-Guide/How-do-I-import-grades-in-the-Gradebook/ta-p/807

df_template = pd.read_csv(f_canvas)
df_template = (
    df_template.drop([0, len(df_template)-1])
               .drop(columns=df_template.columns[5:]) 
)
uid = df_template['SIS User ID'].astype('Int64', copy=False).values
df_upload = df_template.copy()


df_educoder = pd.read_excel(f_educoder, sheet_name=None) 
for task_name, df in df_educoder.items():
    if '作业0' in task_name: continue
    task_name = re.sub(r'^\d*\.', '', task_name) # 去除作业标题前面的 `索引.`
    df_upload[task_name] =  df.set_index(['学号']).reindex(index=uid)['最终成绩'].values


df_upload.to_csv(f'canvas 上传版本.csv', index=False)


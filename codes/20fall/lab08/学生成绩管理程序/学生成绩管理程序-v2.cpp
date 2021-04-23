#include <iostream>
#include <string>
using namespace std;

const int N_COURSES = 3;

struct Student
{
    long long sid;
    char name[50];
    int grades[N_COURSES];

    int total_score() const {
        int score = 0;
        for (int i = 0; i < N_COURSES; ++i) score += grades[i];
        return score;
    }
};

struct StudentManager
{
    Student students[1005];
    int n_students = 0;

    /*
        操作1： 添加学生信息
    */
    void insert_student(bool isupdated=false) {
        int pos = search_by_sid();

        Student& s = students[pos];
        for (int i = 0; i < N_COURSES; ++i) cin >> s.grades[i];
        cin >> ws; // skip whitespace
        cin.getline(s.name, 50);

        if (isupdated) return; // update_student调用时并不增加学生总数
        if (pos < n_students) return; // 更新已存在的学生时并不增加学生总数
        n_students++;
    }

    /*
        操作2： 更新学生信息
    */
    void update_student() {
        insert_student(true);
    }

    /*
        操作3： 按照学号删除学生信息
    */
    void delete_student() {
        int pos = search_by_sid();
        if (pos == n_students) return; // 未找到学生

        // 将后面的学生依次前置一位
        for (int i = pos; i < n_students-1; ++i) { 
            students[i] = students[i+1];
        }
        n_students--;
    }

    /*
        操作4： 按学号查询学生信息
    */
    void search_and_display_by_sid() {
        int pos = search_by_sid();
        if (pos < n_students) display_student(pos);
    }

    /*
        操作5： 按姓名查询学生信息
    */
    void search_and_display_by_name() {
        string name; 
        cin >> ws; // skip white space
        getline(cin, name);

        bubbleSort(students, n_students, true);
        for (int i = 0; i < n_students; ++i) { 
            if (students[i].name == name) display_student(i);
        }
    }

    /*
        操作6： 按学号升序排序显示学生信息
    */
    void sort_and_display_by_sid() {
        bubbleSort(students, n_students, true);
        for (int i = 0; i < n_students; ++i) display_student(i);    
    }

    /*
        操作7： 按总分降序排序显示学生信息
    */
    void sort_and_display_by_total_score() {
        bubbleSort(students, n_students, false);
        for (int i = 0; i < n_students; ++i) display_student(i);    
    }


    bool cmp(const Student& s1, const Student& s2, bool by_sid) {
        if (by_sid) return s1.sid > s2.sid;

        return s1.total_score() < s2.total_score() || 
            (s1.total_score() == s2.total_score() && s1.sid > s2.sid );
    }

    void bubbleSort(Student* A, int n, bool by_sid) {
        // sort by sid or by total_score
        
        for (int i=n-1; i>=0; --i) {
            bool exist_swap = false;
            for (int j=0; j<i; ++j) {
                if (cmp(A[j], A[j+1], by_sid)) 
                    swap(A[j], A[j+1]), exist_swap = true;
            }
            if (! exist_swap) break;
        }
    }

    void display_student(int pos) {
        Student& s = students[pos];
        cout << s.sid << " " << s.name << " ";
        for (int i = 0; i < N_COURSES; ++i) cout << s.grades[i] << " ";
        cout << endl;
    }

    int search_by_sid() {
        long long sid; cin >> sid;

        // 搜索学生在数组中的位置
        int pos = 0;
        while (pos < n_students && students[pos].sid != sid) pos++;
        students[pos].sid = sid;

        return pos;
    }

};




int main()
{
    // freopen("lab08_学生成绩管理程序_cases/case_04.in", "r", stdin);

    StudentManager manager;
    int op; 
    while (true) {
        cin >> op;
        switch (op)
        {
        case 1:
            manager.insert_student();
            break;
        case 2:
            manager.update_student();
            break;
        case 3:
            manager.delete_student();
            break;
        case 4:
            manager.search_and_display_by_sid();
            break;
        case 5:
            manager.search_and_display_by_name();
            break;
        case 6:
            manager.sort_and_display_by_sid();
            break;
        case 7:
            manager.sort_and_display_by_total_score();
            break;
        
        default:
            return 0;
        }
    }

    return 0;
}





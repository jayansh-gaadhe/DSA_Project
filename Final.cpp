#include <bits/stdc++.h>
using namespace std;
ifstream in2;
class Course;
class Hash;
class slot;

class Hash
{
    string code; // key values of hash tables, they are unique.
    int lec;     // No. of lectures of Courses
    int flag;    // To indicate that particular hash(cource) is stored in a slot.

public:
    list<Course> chain;         //list of programs having same courses

    void set_code(string s);
    string get_code();
    int get_lecture();
    void set_lecture(int l);
    int get_flag();
    void set_flag(int f);
};
void Hash ::set_lecture(int l)
{
    lec = l;
}

int Hash ::get_lecture()
{
    return lec;
}
void Hash ::set_flag(int f)
{
    flag = f;
}

int Hash ::get_flag()
{
    return flag;
}

void Hash ::set_code(string s)
{
    code = s;
}
string Hash ::get_code()
{
    return code;
}
int repeat_course(int size, string s, string arr[])     //To check that particular course is unique(means not stored in arr before.)
{
    for (int i = 0; i < size; i++)
    {
        if (s == arr[i])
        {
            return 1;
        }
    }
    return 0;
}

class slot
{
private:
    string code[100];
    string pg[100]; // program
    int slot_num;
    int sem[100];
    string fac[100];
    string type[100];
    // Course *a;
    int lecture;
    int count; // we use count for number of pg/code in this slot
    int ICTA[8];        //these arrays are indicating that for particular program of a particular sem ,
                        //a course is alloted in the slot or not
    int ICTB[8];        
    int CS[8];          
    int MNC[8];
    int EVD[8];

public:
    void initialize_slot(int n, int l, int size)
    {
        slot_num = n;
        lecture = l;
        count = 0;
        ICTA[1] = ICTA[2] = ICTA[3] = ICTA[4] = ICTA[5] = ICTA[6] = ICTA[7] = ICTA[8] = 0;
        ICTB[1] = ICTB[2] = ICTB[3] = ICTB[4] = ICTB[5] = ICTB[6] = ICTB[7] = ICTB[8] = 0;
        CS[1] = CS[2] = CS[3] = CS[4] = CS[5] = CS[6] = CS[7] = CS[8] = 0;
        MNC[1] = MNC[2] = MNC[3] = MNC[4] = MNC[5] = MNC[6] = MNC[7] = MNC[8] = 0;
        EVD[1] = EVD[2] = EVD[3] = EVD[4] = EVD[5] = EVD[6] = EVD[7] = EVD[8] = 0;
    }
    string get_code();
    string get_program();
    void set_code(string c);
    void set_program(string p);
    void make_slot(int a_size, Course *arr, int h_size, Hash h[]);
    void display_slot();
    int check_filled(Course c);
    void fill(Course &c);
    void set_sem(int s,int i);
    void set_faculty(string f,int i);
    int get_sem(int i);
    string get_faculty(int i);
    void set_type(string t,int i);
    string get_type(int i);

};

void slot :: set_sem(int s,int i){
    sem[i]=s;
}
void slot :: set_faculty(string s,int i){
    fac[i]=s;  
}
int slot :: get_sem(int i){
    return sem[i];
}
string slot :: get_faculty(int i){
    return fac[i];
}
void slot :: set_type(string t,int i){
    type[i]=t;
}
string slot :: get_type(int i){
    return type[i];
}


void slot ::display_slot()
{
    cout << "Slot : M" << slot_num << endl;
    for (int i = 0; i < count; i++)
    {
        cout <<"Sem-"<<sem[i]<<" "<< pg[i] << " "<<code[i] << " "<<lecture<<" " <<type[i]<<" "<<fac[i]<< endl;
    }
    cout << endl;
}

class Course
{
    string code;
    string course_name;
    string faculty;
    string type;
    int lecture;
    string program;
    int sem;
    int ass_slot;           //ass_slot=0 ,if non slot is assigned to the course
                            //ass_alot= slot_number , if a slot assigned to the course

public:
    Course()
    {
        ass_slot = 0;
    }
    void read_data();
    int get_sem();
    void get_data();
    string get_program();
    string get_course();
    bool isCore();
    int get_lecture();
    void set_slot(int s);
    int get_slot();
    string get_code();
    string get_faculty();
    string get_type();
};
string Course :: get_type(){
    return type;
}

string Course ::get_code()
{
    return code;
}
int Course ::get_slot()
{
    return ass_slot;
}
void Course ::set_slot(int s)
{
    ass_slot = s;
}
string Course ::get_faculty()
{
    return faculty;
}

bool repeat_prof(string c, string prof[], int count)        //To check that in one slot a particular proffesor has only one course.
                                                            //i.e. one faculty should have only one course in a single slot.
{
    for (int i = 0; i < count; i++)
    {
        if (prof[i] == c)
        {
            return true;
        }
    }
    return false;
}

int Course ::get_lecture()
{
    return lecture;
}

string Course ::get_course()
{
    return course_name;
}
bool Course ::isCore()
{
    return type == "Core";
}
int Course ::get_sem()
{
    return sem;
}
void Course ::read_data()
{
    string content;
    int lec;
    getline(in2, content, ',');
    code = content;
    getline(in2, content, ',');
    course_name = content;
    in2 >> lecture;
    getline(in2, content, ',');
    getline(in2, content, ',');
    type = content;
    getline(in2, content, ',');
    faculty = content;
    getline(in2, content, ',');
    program = content;
    in2 >> sem;
    getline(in2, content);
}

void Course ::get_data()
{
    cout << code << "," << course_name << "," << lecture << "," << type << "," << faculty << "," << program << "," << sem << endl;
}
string Course ::get_program()
{
    return program;
}
void count_n_lecture_courses(int size, Course arr[], string prog, int sem, int *count)
{
    int i = 0;
    for (i; i < size; i++)
    {
        if (!arr[i].isCore())
        {
            continue;
        }
        if (arr[i].get_program() == prog && arr[i].get_sem() == sem)
        {
            int l = arr[i].get_lecture();
            if (l == 1)
            {
                count[1]++;
            }
            else if (l == 2)
            {
                count[2]++;
            }
            else if (l == 3)
            {
                count[3]++;
            }
        }
    }
}
void no_of_slots(int size, Course arr[], int *max)
{
    int m[5];
    int max1, max2, max3, max4, max5;
    max1 = max2 = max3 = max4 = max5 = 0;
    for (int i = 1; i <= 8; i++)
    {
        m[0] = m[1] = m[2] = m[3] = m[4] = 0;
        count_n_lecture_courses(size, arr, "ICTA", i, m);
        if (m[1] > max1)
        {
            max1 = m[1];
        }
        if (m[2] > max2)
        {
            max2 = m[2];
        }
        if (m[3] > max3)
        {
            max3 = m[3];
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        m[0] = m[1] = m[2] = m[3] = m[4] = 0;
        count_n_lecture_courses(size, arr, "CS", i, m);
        if (m[1] > max1)
        {
            max1 = m[1];
        }
        if (m[2] > max2)
        {
            max2 = m[2];
        }
        if (m[3] > max3)
        {
            max3 = m[3];
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        m[0] = m[1] = m[2] = m[3] = m[4] = 0;
        count_n_lecture_courses(size, arr, "MNC", i, m);
        if (m[1] > max1)
        {
            max1 = m[1];
        }
        if (m[2] > max2)
        {
            max2 = m[2];
        }
        if (m[3] > max3)
        {
            max3 = m[3];
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        m[0] = m[1] = m[2] = m[3] = m[4] = 0;
        count_n_lecture_courses(size, arr, "EVD", i, m);
        if (m[1] > max1)
        {
            max1 = m[1];
        }
        if (m[2] > max2)
        {
            max2 = m[2];
        }
        if (m[3] > max3)
        {
            max3 = m[3];
        }
    }
    max[1] = max1;
    max[2] = max2;
    max[3] = max3;
}

/*condition for slots making:
1.no repitition of courses of the same program (i.e. IT112 and PC110 can't be set in same slot)
2.one proffesor must not have two courses in same slot.
3.total no. of slot is = max no. cources of a single program

*/

int slot ::check_filled(Course c)
{
    if (c.get_program() == "ICTA")
    {
        for (int i = 0; i < 8; i++)
        {
            if (c.get_sem() == i)
            {
                return ICTA[i];
            }
        }
    }

    if (c.get_program() == "ICTB")
    {
        for (int i = 0; i < 8; i++)
        {
            if (c.get_sem() == i)
            {
                return ICTB[i];
            }
        }
    }
    if (c.get_program() == "CS")
    {
        for (int i = 0; i < 8; i++)
        {
            if (c.get_sem() == i)
            {
                return CS[i];
            }
        }
    }
    if (c.get_program() == "MNC")
    {
        for (int i = 0; i < 8; i++)
        {
            if (c.get_sem() == i)
            {
                return MNC[i];
            }
        }
    }
    if (c.get_program() == "EVD")
    {
        for (int i = 0; i < 8; i++)
        {
            if (c.get_sem() == i)
            {
                return EVD[i];
            }
        }
    }
}

void slot ::fill(Course &c)
{
    if (c.get_program() == "ICTA")
    {
        for (int i = 0; i < 8; i++)
        {
            if (c.get_sem() == i)
            {
                ICTA[i] = 1;
                return;
            }
        }
    }
    if (c.get_program() == "ICTB")
    {
        for (int i = 0; i < 8; i++)
        {
            if (c.get_sem() == i)
            {
                ICTB[i] = 1;
                return;
            }
        }
    }
    if (c.get_program() == "CS")
    {
        for (int i = 0; i < 8; i++)
        {
            if (c.get_sem() == i)
            {
                CS[i] = 1;
                return;
            }
        }
    }
    if (c.get_program() == "MNC")
    {
        for (int i = 0; i < 8; i++)
        {
            if (c.get_sem() == i)
            {
                MNC[i] = 1;
                return;
            }
        }
    }
    if (c.get_program() == "EVD")
    {
        for (int i = 0; i < 8; i++)
        {
            if (c.get_sem() == i)
            {
                EVD[i] = 1;
                return;
            }
        }
    }
}

void slot ::make_slot(int a_size, Course *arr, int h_size, Hash *h)
{
    string prof[65];

    int fac = 0; // no of different faculties,whose courses are alloted this slot
    count = 0;   //  counts how many courses are alloted this particular slot.

    for (int i = 0; i < h_size; i++)
    {
        if (h[i].get_lecture() != lecture || !h[i].chain.front().isCore() || h[i].get_flag() == 1 || repeat_prof(h[i].chain.front().get_faculty(), prof, fac))
        {
            continue;
        }
        int ck = 0;
        for (auto j : h[i].chain)
        {
            if (check_filled(j) == 1)
            {
                ck = 1;
                break;
            }
        }
        if (ck == 1)
        {
            continue;
        }
        for (auto j : h[i].chain)
        {
            
            code[count] = h[i].get_code();
            pg[count] = j.get_program();
            sem[count]=j.get_sem();
            set_faculty(j.get_faculty(),count);
            type[count]=j.get_type();
            j.set_slot(slot_num);
            


            if (repeat_prof(j.get_faculty(), prof, fac) == 0)
            {
                prof[fac] = j.get_faculty();
                fac++;
            }
            fill(j);
            // a[count]=j;
            count++;
        }
        h[i].set_flag(1);
    }
}

int main()
{
    int count = 0;
    ifstream in;
    string content;
    string fname;
    cout << "Enter the name of the input CSV file : ";
    cin >> fname;
    in.open(fname);
    in2.open(fname);
    while (in.peek() != EOF)
    {
        getline(in, content);
        count++;
    }
    cout << "Count is : " << count << endl;
    Course arr[count];
    for (int i = 0; i < count; i++)
    {
        arr[i].read_data();
    }

    int max_course[5];
    no_of_slots(count, arr, max_course);
    cout << "Maximum 3 lec : " << max_course[3] << endl;
    cout << "Maximum 2 lec : " << max_course[2] << endl;
    cout << "Maximum 1 lec : " << max_course[1] << endl;
    int tot_slot = max_course[1] + max_course[2] + max_course[3];
    cout << "Tota slots required : " << tot_slot << endl<<endl;
    slot sl[tot_slot];

    int sl_num = 1;
    for (int i = 0; i < max_course[3]; i++)
    {
        sl[sl_num - 1].initialize_slot(sl_num, 3, count);   //work as a constructor
        sl_num++;
    }
    for (int i = 0; i < max_course[2]; i++)
    {
        sl[sl_num - 1].initialize_slot(sl_num, 2, count);
        sl_num++;
    }
    for (int i = 0; i < max_course[1]; i++)
    {
        sl[sl_num - 1].initialize_slot(sl_num, 1, count);
        sl_num++;
    }

    int t = 0;
    string temp[count]; // To compare
    for (int i = 0; i < count; i++)
    {
        if (repeat_course(t, arr[i].get_code(), temp) == 0 && arr[i].isCore())
        {
            temp[t] = arr[i].get_code();
            t++;
        }
    }
    Hash h[t];
    for (int i = 0; i < t; i++)
    {
        h[i].set_code(temp[i]);
        h[i].set_flag(0);
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (arr[i].get_code() == h[j].get_code())
            {

                h[j].chain.push_front(arr[i]);
                h[j].set_lecture(arr[i].get_lecture());
            }
        }
    }
    /*for (int i = 0; i < t; i++)
    {
        cout << h[i].get_code() << " " << h[i].get_lecture() << "->";
        for (auto i : h[i].chain)
        {
            cout << i.get_program() << "," << i.get_sem() << " ";
        }
        cout << endl;
    }*/

    for (int i = 0; i < tot_slot; i++)
    {
        sl[i].make_slot(count, arr, t, h);
    }
    for (int i = 0; i < sl_num - 1; i++)
    {
        sl[i].display_slot();
    }

    return 0;
}
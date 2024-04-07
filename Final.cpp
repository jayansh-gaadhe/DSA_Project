#include <bits/stdc++.h>
using namespace std;
ifstream in2;
class Course;
class Hash;
class slot;
#include <iostream>
using namespace std;

class node
{
public:
    int sl_num, priority;
    node *next;
};

class PriorityQ
{
private:
    node *head;

public:
    PriorityQ()
    {
        head = NULL;
    }

    void dequeue();
    void enqueue(int, int);
    void display();
    int front_priority();
    int front_sl_num();
    void dequeue_in_between(int slot);
    int size();
};
int PriorityQ ::size()
{
    node *p = head;
    int s = 0;
    while (p != NULL)
    {
        p = p->next;
        s++;
    }
    return s;
}
int PriorityQ ::front_priority()
{
    return head->priority;
}
int PriorityQ ::front_sl_num()
{
    return head->sl_num;
}
void PriorityQ::enqueue(int x, int pri)
{
    node *newnode = new node;
    newnode->sl_num = x;
    newnode->priority = pri;
    newnode->next = NULL;

    if (head == NULL || pri > head->priority)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        node *p = head;
        while (p->next != NULL && pri < p->next->priority)
        {
            p = p->next;
        }
        newnode->next = p->next;
        p->next = newnode;
    }
}

void PriorityQ ::dequeue()
{
    int x = -1;
    if (head == NULL)
    {
        // cout << "Priority Queue is empty!" << endl;
    }
    else
    {
        node *p = head;
        x = head->sl_num;
        if (head->next == NULL)
            head = NULL;
        else
            head = head->next;
        delete p;
    }
    return;
}



class Hash
{
    string code; // key values of hash tables, they are unique.
    int lec;     // No. of lectures of Courses
    int flag;    // To indicate that particular hash(cource) is stored in a slot.

public:
    list<Course> chain; // list of programs having same courses

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
int repeat_course(int size, string s, string arr[]) // To check that particular course is unique(means not stored in arr before.)
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
    int faculty = 0; // number of different faculties
    string type[100];
    int lecture;
    int count; // we use count for number of pg/code in this slot
    int lec_count = 0;
    int ICTA[8] = {0}; // these arrays are indicating that for particular program of a particular sem ,
                       // a course is alloted in the slot or not
    int ICTB[8] = {0};
    int CS[8] = {0};
    int MNC[8] = {0};
    int EVD[8] = {0};

public:
    void initialize_slot(int n, int l, int size)
    {
        slot_num = n;
        lecture = l;
        count = 0;
    }
    string get_code();
    string get_program();
    void set_code(string c);
    void set_program(string p);
    void make_slot(int a_size, Course *arr, int h_size, Hash h[]);
    void display_slot();
    int check_filled(Course c);
    void fill(Course &c);
    void set_sem(int s, int i);
    void set_faculty(string f, int i);
    int get_sem(int i);
    int get_lec_count();
    void inc_lec_count(); // increment function
    int get_lec();
    string get_faculty(int i);
    void set_type(string t, int i);
    string get_type(int i);
    friend void display_slot_in_csv(int tot_sl, slot sl[]);
    friend void make_time_table(int total, slot s[], int (&tt)[6][6]);
    friend int repeat_fac_in_prev_slot(slot prev, slot curr);
    friend string return_course_for_tt(string prog, int sem, slot sl);
    friend void pg_wise_tt(int total, slot sl[], int tt[6][6]);
    friend void fc_wise_tt(slot sl[], int tt[6][6]);
};

void slot ::set_sem(int s, int i)
{
    sem[i] = s;
}
void slot ::set_faculty(string s, int i)
{
    fac[i] = s;
}
int slot ::get_sem(int i)
{
    return sem[i];
}
string slot ::get_faculty(int i)
{
    return fac[i];
}
void slot ::set_type(string t, int i)
{
    type[i] = t;
}
string slot ::get_type(int i)
{
    return type[i];
}

void slot ::display_slot()
{
    // to display in terminal
    cout << "Slot : M" << slot_num << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "Sem-" << sem[i] << " " << pg[i] << " " << code[i] << " " << lecture << " " << type[i] << " " << fac[i] << endl;
    }
    cout << endl;
}
void slot ::inc_lec_count()
{
    lec_count++;
}
int slot ::get_lec_count()
{
    return lec_count;
}
int slot ::get_lec()
{
    return lecture;
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
    int ass_slot; // ass_slot=0 ,if non slot is assigned to the course
                  // ass_alot= slot_number , if a slot assigned to the course

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
string Course ::get_type()
{
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

bool repeat_prof(string c, string prof[], int count)
{ // To check that in one slot a particular proffesor has only one course.
  // i.e. one faculty should have only one course in a single slot.
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

    faculty = 0; // no of different faculties,whose courses are alloted this slot
    count = 0;   //  counts how many courses are alloted this particular slot.

    for (int i = 0; i < h_size; i++)
    {
        /*
        #Continue (skip the Course/Hash) if
        ->Lecture of course is not matching with lecture of slots
        ->Course is not Core
        ->All the course of hash are alloted in some other slot
        ->The Proffesor already have a course in this slot
        -> One course of a particular program and sem is already there in the slot

        */

        if (h[i].get_lecture() != lecture || !h[i].chain.front().isCore() || h[i].get_flag() == 1 || repeat_prof(h[i].chain.front().get_faculty(), prof, faculty))
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
        ck = 0;

        for (auto j : h[i].chain)
        {
            if (repeat_prof(j.get_faculty(), prof, faculty) == 1)
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
            sem[count] = j.get_sem();
            fac[count] = j.get_faculty();
            type[count] = j.get_type();
            j.set_slot(slot_num);

            if (repeat_prof(j.get_faculty(), prof, faculty) == 0)
            {
                prof[faculty] = j.get_faculty();
                faculty++;
            }
            fill(j);
            count++;
        }
        h[i].set_flag(1);
    }
}

void display_slot_in_csv(int tot_sl, slot sl[])
{
    // to display in csv
    ofstream out;
    string fname; // file name
    cout << "Enter the name of csv file to save the slots : ";
    cin >> fname;
    out.open(fname);
    for (int j = 0; j < tot_sl; j++)
    {
        out << "Slot : M" << sl[j].slot_num << endl;
        out << "SEM,PROGRAM,CODE,LECTURE,TYPE,FACULTY" << endl;

        for (int i = 0; i < sl[j].count; i++)
        {
            out << "Sem-" << sl[j].sem[i] << "," << sl[j].pg[i] << "," << sl[j].code[i] << "," << sl[j].lecture << "," << sl[j].type[i] << "," << sl[j].fac[i] << endl;
        }
        out << endl;
    }
}
int repeat_fac_in_prev_slot(slot prev, slot curr)
{

    for (int i = 0; i < prev.faculty; i++)
    {
        for (int j = 0; j < curr.faculty; j++)
        {
            if (prev.fac[i] == curr.fac[j])
            {
                return 1;
            }
        }
    }
    return 0;
}
int repeat_slot_in_day(int d, int sl_day[], int slot_num)
{
    for (int i = 0; i < d; i++)
    {
        if (sl_day[i] == slot_num)
        {
            return 1;
        }
    }
    return 0;
}

    
void PriorityQ ::display()
{
    node *p = head;
    while (p != NULL)
    {
        cout << "data: " << p->sl_num << " and ";
        cout << "Priority: " << p->priority << endl;
        p = p->next;
    }
}
void PriorityQ ::dequeue_in_between(int slot)
{
    node *p;
    node *q;
    p = head;
    q = head->next;
    if (p->sl_num == slot)
    {
        head = q;
        delete (p);
        return;
    }
    while (q != NULL && q->sl_num != slot)
    {
        p = p->next;
        q = q->next;
    }
    if (q == NULL)
    {
        return;
    }
    // enqueue(q->sl_num, q->priority - 1);
    p->next = q->next;
    delete (q);
}
void make_time_table(int total, slot *s, int (&tt)[6][6])
{
    /*conditions for Time table
    1.one slot can not repeat on that day
    2.perticular faculty must not have two consecutive lecture
    3.perticular slot should be placed on the basis of lecture of that slot*/
    PriorityQ p;
    int filled_box = 0;
    int total_box = 0;
    int freq_zero = 0;

    for (int i = 0; i < total; i++)
    {
        total_box += s[i].lecture;
    }
    for (int i = 0; i < total; i++)
    {
        p.enqueue(s[i].slot_num, s[i].lecture);
    }
    p.enqueue(0, 25 - total_box);

    for (int j = 1; j <= 5; j++)
    {
        if (filled_box == 25)
        {
            break;
        }
        if (p.size() == 0)
        {
            break;
        }
        int sl_day[5] = {0}; // slots of day
        int d = 0;
        for (int i = 1; i <= 5; i++)
        {

            if (filled_box == 25)
            {
                break;
            }
            if (p.size() == 0)
            {
                break;
            }
            if (j == 5)
            {
                p.dequeue_in_between(0);
            }
            if (p.size() == 1 && p.front_priority() == 1)
            {

                tt[i][j] = p.front_sl_num();
                filled_box = 25;
                break;
            }
            if (i == 1)
            {
                if (p.front_priority() != 1)
                {

                    p.enqueue(p.front_sl_num(), p.front_priority() - 1);
                }
                tt[i][j] = p.front_sl_num();
                sl_day[d] = tt[i][j];
                d++;
                filled_box++;
                p.dequeue();
                continue;
            }
            else
            {
                int ck = 0;
                if (tt[i - 1][j] == 0)
                {
                    int sl[total];
                    int pri[total];
                    int cnt = 0;
                    while (ck != 1)
                    {
                        if (repeat_slot_in_day(d, sl_day, p.front_sl_num()))
                        {
                            if (p.front_sl_num() == 0 && p.front_priority() == 1)
                            {
                                p.dequeue();
                                filled_box++;
                                continue;
                            }
                            sl[cnt] = p.front_sl_num();
                            pri[cnt] = p.front_priority();
                            cnt++;
                            p.dequeue();
                            continue;
                        }
                        else
                        {
                            if (p.front_priority() != 1)
                            {
                                p.enqueue(p.front_sl_num(), p.front_priority() - 1);
                            }
                            tt[i][j] = p.front_sl_num();
                            sl_day[d] = tt[i][j];
                            d++;
                            filled_box++;
                            p.dequeue();
                            for (int m = 0; m < cnt; m++)
                            {
                                p.enqueue(sl[m], pri[m]);
                            }
                            break;
                        }
                    }
                }
                else
                {
                    int sl[total];
                    int pri[total];
                    int cnt = 0;
                    while (ck != 1)
                    {
                        if (repeat_slot_in_day(d, sl_day, p.front_sl_num()) || repeat_fac_in_prev_slot(s[tt[i - 1][j] - 1], s[p.front_sl_num()]))
                        {

                            if (p.front_sl_num() == 0 && p.front_priority() == 1)
                            {

                                p.dequeue();
                                filled_box++;
                                continue;
                            }
                            sl[cnt] = p.front_sl_num();
                            pri[cnt] = p.front_priority();
                            cnt++;
                            p.dequeue();
                            continue;
                        }
                        else
                        {
                            if (p.front_priority() != 1)
                            {
                                p.enqueue(p.front_sl_num(), p.front_priority() - 1);
                            }
                            tt[i][j] = p.front_sl_num();
                            sl_day[d] = tt[i][j];
                            d++;
                            filled_box++;
                            p.dequeue();
                            for (int m = 0; m < cnt; m++)
                            {
                                p.enqueue(sl[m], pri[m]);
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

void tt_in_csv(int tt[6][6])
{
    ofstream out;
    cout << "Enter the name of the csv file for time-table : ";
    string fname;
    cin >> fname;
    out.open(fname);
    out << "Time,Monday,Tuesday,Wednesday,Thursday,Friday" << endl;
    int s = 8;
    int e = 9;
    for (int i = 1; i < 6; i++)
    {
        out << s << ":00 - " << s << ":50 , ";
        for (int j = 1; j < 6; j++)
        {
            if (tt[i][j] == 0)
            {
                out << "Free , ";
                continue;
            }
            out << "M" << tt[i][j] << " , ";
        }
        s++;
        e++;
        out << endl;
    }
}

void pg_wise_tt(int total, slot sl[], int tt[6][6])
{
    cout << "Enter the program : ";
    string prog;
    int sem;
    cin >> prog;
    cout << "Enter the sem : ";
    cin >> sem;
    ofstream o2;
    string fname;
    cout << "Enter the csv file name to store time table of " << prog << "Sem-" << sem << " : ";
    cin >> fname;
    o2.open(fname);

    o2 << "Time-Table For " << prog << " Sem-" << sem << endl;
    o2 << "Time,Monday,Tuesday,Wednesday,Thursday,Friday" << endl;

    int s = 8;

    for (int i = 1; i < 6; i++)
    {
        o2 << s << ":00 - " << s << ":50 , ";
        for (int j = 1; j < 6; j++)
        {
            if (tt[i][j] == 0)
            {
                o2 << "Free , ";
                continue;
            }
            
            int k;
            for (k = 0; k < sl[tt[i][j] - 1].count; k++)
            {
                if (sl[tt[i][j] - 1].sem[k] == sem && sl[tt[i][j] - 1].pg[k] == prog)
                {
                    o2 << sl[tt[i][j] - 1].code[k] << " , ";
                    break;
                }
            }
            if (k == sl[tt[i][j] - 1].count)
            {
                o2 << "Free , ";
            }

        }
        s++;

        o2 << endl;
    }
}
void fc_wise_tt(slot sl[], int tt[6][6])
{
    string fac;
    cout << "Enter short name of Faculty : ";
    cin >> fac;
    ofstream out;
    string fname;
    cout << "Enter the csv file name to store time table of " << fac << " : ";
    cin >> fname;
    out.open(fname);
    int s = 8;
    out << "Time-Table For " << fac << endl;
    out << "Time,Monday,Tuesday,Wednesday,Thursday,Friday" << endl;

    for (int i = 1; i < 6; i++)
    {
        out << s << ":00 - " << s << ":50 , ";
        for (int j = 1; j < 6; j++)
        {
            if (tt[i][j] == 0)
            {
                out << "Free  , ";
                continue;
            }

            int k;
            for (k = 0; k < sl[tt[i][j] - 1].count; k++)
            {
                if (sl[tt[i][j] - 1].fac[k] == fac)
                {
                    out << sl[tt[i][j] - 1].code[k] << " , ";
                    break;
                }
            }
            if (k == sl[tt[i][j] - 1].count)
            {
                out << "Free  , ";
            }

        }
        s++;

        out << endl;
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
    // cout << "Count is : " << count << endl;
    Course arr[count];
    for (int i = 0; i < count; i++)
    {
        arr[i].read_data();
    }

    int max_course[5];
    no_of_slots(count, arr, max_course);
    /*cout << "Maximum 3 lec : " << max_course[3] << endl;
    cout << "Maximum 2 lec : " << max_course[2] << endl;
    cout << "Maximum 1 lec : " << max_course[1] << endl;*/
    int tot_slot = max_course[1] + max_course[2] + max_course[3];
    /*cout << "Tota slots required : " << tot_slot << endl
         << endl;*/
    slot sl[tot_slot];

    int sl_num = 1;
    for (int i = 0; i < max_course[3]; i++)
    {
        sl[sl_num - 1].initialize_slot(sl_num, 3, count); // work as a constructor
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
    /*

    ****Do not remove this for loop****

    for (int i = 0; i < t; i++)
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
    /*

    ***Do not remove thi for loop ***

    for (int i = 0; i < sl_num - 1; i++)
    {
        sl[i].display_slot();
    }*/
    display_slot_in_csv(tot_slot, sl);
    int tt[6][6] = {{0}, {0}, {0}, {0}, {0}, {0}};
    make_time_table(tot_slot, sl, tt);
    tt_in_csv(tt);
    cout << "Enter 1.For Branch/Program wise time-table." << endl
         << "Enter 2.For Faculty's time-table." << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        pg_wise_tt(tot_slot, sl, tt);
        break;

    case 2:
        fc_wise_tt(sl, tt);
        break;
    default:
        cout << "Invalid Integer!! :(" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
ifstream in2;

class Course
{
    string code;
    string course_name;
    string faculty;
    string type;
    int lecture;
    string program;
    int sem;
    int ass_slot;

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
    string *get_prof_ref();
    string get_faculty();
};
string *Course ::get_prof_ref()
{
    return &faculty;
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

class Slot
{
    int slot_num;
    int lec;
    int count;
    char **prof;
    int ICTA[9];
    int ICTB[9];
    int CS[9];
    int MNC[9];
    int EVD[9];

    /*string ICTA1;
    string ICTB1;
    string CS1;
    string MNC1;
    string EVD1;
    string ICTA2;
    string ICTB2;
    string CS2;
    string MNC2;
    string EVD2;
    string ICTA3;
    string ICTB3;
    string CS3;
    string MNC3;
    string EVD3;
    string ICTA4;
    string ICTB4;
    string CS4;
    string MNC4;
    string EVD4;
    string ICTA5;
    string ICTB5;
    string CS5;
    string MNC5;
    string EVD5;
    string ICTA6;
    string ICTB6;
    string CS6;
    string MNC6;
    string EVD6;
    string ICTA7;
    string ICTB7;
    string CS7;
    string MNC7;
    string EVD7;
    string ICTA8;
    string ICTB8;
    string CS8;
    string MNC8;
    string EVD8;*/
public:
    Slot() {}
    void initialize_slot(int n, int l)
    {
        lec = l;
        slot_num = n;
        ICTA[1] = ICTA[2] = ICTA[3] = ICTA[4] = ICTA[5] = ICTA[6] = ICTA[7] = ICTA[8] = 0;
        ICTB[1] = ICTB[2] = ICTB[3] = ICTB[4] = ICTB[5] = ICTB[6] = ICTB[7] = ICTB[8] = 0;
        CS[1] = CS[2] = CS[3] = CS[4] = CS[5] = CS[6] = CS[7] = CS[8] = 0;
        MNC[1] = MNC[2] = MNC[3] = MNC[4] = MNC[5] = MNC[6] = MNC[7] = MNC[8] = 0;
        EVD[1] = EVD[2] = EVD[3] = EVD[4] = EVD[5] = EVD[6] = EVD[7] = EVD[8] = 0;
    }
    void make_slot(int size, Course *arr);
    int get_slot_num()
    {
        return slot_num;
    }
    int get_lecture()
    {
        return lec;
    }
};

bool repeat_prof(Course c, string prof[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (prof[i] == c.get_faculty())
        {
            return true;
        }
    }
    return false;
}

void Slot ::make_slot(int size, Course *arr)
{
    string prof[65];
    int fac = 0; // no of different faculties,whose courses are alloted this slot
    count = 0;   // counts how many courses are alloted this particular slot.
    for (int i = 0; i < size; i++)
    {
        if (!arr[i].isCore() || arr[i].get_lecture() != lec || arr[i].get_slot() != 0 || repeat_prof(arr[i], prof, fac))
        {
            continue;
        }
        if (arr[i].get_program() == "ICTA" && ICTA[arr[i].get_sem()] != 1)
        {
            arr[i].set_slot(slot_num);
            ICTA[arr[i].get_sem()] = 1;
            prof[count] = arr[i].get_faculty();
            count++;
            fac++;

            cout << arr[i].get_code() << " " << arr[i].get_course() << " " << arr[i].get_program() << " " << arr[i].get_slot() << " " << arr[i].get_lecture() << endl;
        }
        else if (arr[i].get_program() == "ICTB" && ICTB[arr[i].get_sem()] != 1)
        {
            arr[i].set_slot(slot_num);
            ICTB[arr[i].get_sem()] = 1;
            prof[count] = arr[i].get_faculty();
            count++;
            fac++;

            cout << arr[i].get_code() << " " << arr[i].get_course() << " " << arr[i].get_program() << " " << arr[i].get_slot() << " " << arr[i].get_lecture() << endl;
            for (int j = 0; j < size; j++)
            {
                if (!arr[j].isCore() || arr[i].get_lecture() != lec || arr[i].get_slot() != 0 || arr[i].get_code() != arr[j].get_code())
                {
                    continue;
                }
                string temp = arr[j].get_program();
                if (temp == "MNC" && MNC[arr[j].get_sem()] != 1)
                {
                    arr[j].set_slot(slot_num);
                    MNC[arr[j].get_sem()] = 1;
                    prof[count] = arr[j].get_faculty();
                    count++;

                    cout << arr[i].get_code() << " " << arr[i].get_course() << " " << arr[i].get_program() << " " << arr[i].get_slot() << " " << arr[i].get_lecture() << endl;
                }
                if (temp == "EVD" && EVD[arr[j].get_sem()] != 1)
                {
                    arr[j].set_slot(slot_num);
                    EVD[arr[j].get_sem()] = 1;
                    prof[count] = arr[j].get_faculty();
                    count++;

                    cout << arr[i].get_code() << " " << arr[i].get_course() << " " << arr[i].get_program() << " " << arr[i].get_slot() << " " << arr[i].get_lecture() << endl;
                }
                if (temp == "CS" && CS[arr[j].get_sem()] != 1)
                {
                    arr[j].set_slot(slot_num);
                    CS[arr[j].get_sem()] = 1;
                    prof[count] = arr[j].get_faculty();
                    count++;

                    cout << arr[i].get_code() << " " << arr[i].get_course() << " " << arr[i].get_program() << " " << arr[i].get_slot() << " " << arr[i].get_lecture() << endl;
                }
            }
        }
        else if (arr[i].get_program() == "CS" && CS[arr[i].get_sem()] != 1)
        {
            arr[i].set_slot(slot_num);
            CS[arr[i].get_sem()] = 1;
            prof[count] = arr[i].get_faculty();
            count++;
            fac++;

            cout << arr[i].get_code() << " " << arr[i].get_course() << " " << arr[i].get_program() << " " << arr[i].get_slot() << " " << arr[i].get_lecture() << endl;
        }
        else if (arr[i].get_program() == "MNC" && MNC[arr[i].get_sem()] != 1)
        {
            arr[i].set_slot(slot_num);
            MNC[arr[i].get_sem()] = 1;
            prof[count] = arr[i].get_faculty();
            count++;
            fac++;

            cout << arr[i].get_code() << " " << arr[i].get_course() << " " << arr[i].get_program() << " " << arr[i].get_slot() << " " << arr[i].get_lecture() << endl;
        }
        else if (arr[i].get_program() == "EVD" && EVD[arr[i].get_sem()] != 1)
        {
            arr[i].set_slot(slot_num);
            EVD[arr[i].get_sem()] = 1;
            prof[count] = arr[i].get_faculty();
            count++;
            fac++;

            cout << arr[i].get_code() << " " << arr[i].get_course() << " " << arr[i].get_program() << " " << arr[i].get_slot() << " " << arr[i].get_lecture() << endl;
        }
    }
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
    // getline(in2,content);
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

int count_slot(int size, Course arr[])
{
    int ci[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int cc[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int ce[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int cm[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < size; i++)

    {
        if (!arr[i].isCore())
        {
            continue;
        }
        if (arr[i].get_sem() == 1)
        {
            if (arr[i].get_program() == "ICTA")
            {
                ci[0]++;
            }

            else if (arr[i].get_program() == "EVD")
            {
                ce[0]++;
            }

            else if (arr[i].get_program() == "MNC")
            {
                cm[0]++;
            }
        }
        else if (arr[i].get_sem() == 2)
        {
            if (arr[i].get_program() == "ICTB")
            {
                ci[1]++;
            }

            else if (arr[i].get_program() == "EVD")
            {
                ce[1]++;
            }

            else if (arr[i].get_program() == "MNC")
            {
                cm[1]++;
            }
        }
        else if (arr[i].get_sem() == 3)
        {
            if (arr[i].get_program() == "ICTB")
            {
                ci[2]++;
            }

            else if (arr[i].get_program() == "EVD")
            {
                ce[2]++;
            }

            else if (arr[i].get_program() == "MNC")
            {
                cm[2]++;
            }
        }
        else if (arr[i].get_sem() == 4)
        {
            if (arr[i].get_program() == "ICTB")
            {
                ci[3]++; // count ict
            }
            else if (arr[i].get_program() == "CS")
            {
                cc[3]++;
            }

            else if (arr[i].get_program() == "EVD")
            {
                ce[3]++;
            }

            else if (arr[i].get_program() == "MNC")
            {
                cm[3]++;
            }
        }
        else if (arr[i].get_sem() == 5)
        {
            if (arr[i].get_program() == "ICTB")
            {
                ci[4]++; // count ict
            }
            else if (arr[i].get_program() == "CS")
            {
                cc[4]++;
            }

            else if (arr[i].get_program() == "EVD")
            {
                ce[4]++;
            }

            else if (arr[i].get_program() == "MNC")
            {
                cm[4]++;
            }
        }
        else if (arr[i].get_sem() == 6)
        {
            if (arr[i].get_program() == "ICTB")
            {
                ci[5]++; // count ict
            }
            else if (arr[i].get_program() == "CS")
            {
                cc[5]++;
            }

            else if (arr[i].get_program() == "EVD")
            {
                ce[5]++;
            }

            else if (arr[i].get_program() == "MNC")
            {
                cm[5]++;
            }
        }
        else if (arr[i].get_sem() == 7)
        {
            if (arr[i].get_program() == "ICTB")
            {
                ci[6]++; // count ict
            }
            else if (arr[i].get_program() == "CS")
            {
                cc[6]++;
            }

            else if (arr[i].get_program() == "EVD")
            {
                ce[6]++;
            }

            else if (arr[i].get_program() == "MNC")
            {
                cm[6]++;
            }
        }
        else if (arr[i].get_sem() == 8)
        {
            if (arr[i].get_program() == "ICTB")
            {
                ci[7]++; // count ict
            }
            else if (arr[i].get_program() == "CS")
            {
                cc[7]++;
            }

            else if (arr[i].get_program() == "EVD")
            {
                ce[7]++;
            }

            else if (arr[i].get_program() == "MNC")
            {
                cm[7]++;
            }
        }
    }
    int m1 = max({ci[0], ci[1], ci[2], ci[3], ci[4], ci[5], ci[6], ci[7]});
    int m2 = max({cc[0], cc[1], cc[2], cc[3], cc[4], cc[5], cc[6], cc[7]});
    int m3 = max({cm[0], cm[1], cm[2], cm[3], cm[4], cm[5], cm[6], cm[7]});
    int m4 = max({ce[0], ce[1], ce[2], ce[3], ce[4], ce[5], ce[6], ce[7]});
    int m_final = max({m1, m2, m3, m4});
    return m_final;
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

/*void display_slot(Slot s,int size,Course arr[]){
    for(int i=0;i<size;i++){
        if(arr[i].get_program()=="ICTA" && )
    }
}*/

/*condition for slots making:
1.no repitition of courses of the same program (i.e. IT112 and PC110 can't be set in same slot)
2.one proffesor must not have two courses in same slot.
3.total no. of slot is = max no. cources of a single program

*/

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
    /*for (int i = 0; i < count; i++)
    {
       arr[i].get_data();
    }*/

    // int max_slot=count_slot(count,arr);
    // cout << max_slot;
    int max_course[5];
    no_of_slots(count, arr, max_course);
    cout << "Maximum 3 lec : " << max_course[3] << endl;
    cout << "Maximum 2 lec : " << max_course[2] << endl;
    cout << "Maximum 1 lec : " << max_course[1] << endl;
    int tot_slot = max_course[1] + max_course[2] + max_course[3];
    cout << "Tota slots required : " << tot_slot << endl;
    Slot sl[tot_slot];

    int sl_num = 1;
    for (int i = 0; i < max_course[3]; i++)
    {
        sl[sl_num - 1].initialize_slot(sl_num, 3);
        cout << "Slot " << sl_num << "created." << endl;
        sl_num++;
    }
    for (int i = 0; i < max_course[2]; i++)
    {
        sl[sl_num - 1].initialize_slot(sl_num, 2);
        cout << "Slot " << sl_num << "created." << endl;
        sl_num++;
    }
    for (int i = 0; i < max_course[1]; i++)
    {
        sl[sl_num - 1].initialize_slot(sl_num, 1);
        cout << "Slot " << sl_num << "created." << endl;
        sl_num++;
    }
    for (int i = 0; i < tot_slot; i++)
    {
        cout << sl[i].get_slot_num() << " " << sl[i].get_lecture() << endl;
    }
    /*for(int i=0;i<tot_slot;i++){
        sl[sl_num-1].make_slot(count,arr);
    }*/

    for (int i = 0; i < tot_slot; i++)
    {

        sl[i].make_slot(count, arr);
    }

    /*for(int i=0;i<tot_slot;i++){
        cout<<"Slot "<<i+1<<" : "<<endl;
        for(int j=0;j<count;j++){
            if(arr[j].get_slot() == i+1){
                cout<<arr[j].get_program()<<" "<<arr[j].get_code()<<" "<<arr[j].get_lecture()<<endl;
            }
        }

    }*/
    /*for(int i=0;i<count;i++){
        cout<<arr[i].get_code() <<" "<<arr[i].get_course()<<" "<<arr[i].get_program()<<" "<<arr[i].get_slot()<<endl;
    }*/

    return 0;
    
}
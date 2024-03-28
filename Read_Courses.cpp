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

public:
   void read_data();
   int get_sem();
   void get_data();
   string get_program();
   string get_course();
   bool get_type();
};
class slot
{
   private:
   int slot_num;
   string c_name;
   public:
   void make_slot(Course);
};
string Course :: get_course()
{
   return course_name;
}
bool Course :: get_type()
{
   return type=="Core";
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

int main(){
   int count = 0;
   int ci[8] = {0, 0, 0, 0, 0, 0, 0, 0};
   int cc[8] = {0, 0, 0, 0, 0, 0, 0, 0};
   int ce[8] = {0, 0, 0, 0, 0, 0, 0, 0};
   int cm[8] = {0, 0, 0, 0, 0, 0, 0, 0};
   ifstream in;
   string content;
   string fname;
   cout<<"Enter the name of the input CSV file : ";
   cin>>fname;
   in.open(fname);
   in2.open(fname);
   while (in.peek() != EOF)
   {
      getline(in, content);
      count++;                   //total no.of courses
   }
   cout << "Count is : " << count << endl;
   Course arr[count];
   for (int i = 0; i < count; i++)
   {
      arr[i].read_data();
   }
    for (int i = 0; i < count; i++)

   {
      if (arr[i].get_sem() == 1)
      {
         if (arr[i].get_program() == "ICTB")
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
            cc[6]++;
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
            cc[7]++;
         }
      }
   }
   int m1 = max({ci[0], ci[1], ci[2], ci[3], ci[4], ci[5], ci[6], ci[7]});
   int m2 = max({cc[0], cc[1], cc[2], cc[3], cc[4], cc[5], cc[6], cc[7]});
   int m3 = max({cm[0], cm[1], cm[2], cm[3], cm[4], cm[5], cm[6], cm[7]});
   int m4 = max({ce[0], ce[1], ce[2], ce[3], ce[4], ce[5], ce[6], ce[7]});
   int m_final = max({m1, m2, m3, m4});
   cout << m_final;

   slot s[m_final];
   
   return 0;
}




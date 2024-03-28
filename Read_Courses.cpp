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
}

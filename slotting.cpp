#include<iostream>
#include<string>
#include<algorithm>

using namespace std;




int main()
{
    string slot[15];
    struct data
    {
        string course_code;
        char type;// c for core and e for elective
        string program;
        /* bi for btech ict, bm for btech mnc,bc for btech cs, be for betch evd
        miv for mtech ict with vlsi, miml for mtech ict with machine learning,miss for mtech ict signal and systems,me for mtech ec
        msd for msc data science,msi for msc it,msa for msc agriculture analysis
        md for masters of design */
        
        int year;
        int credit; //lecture credits only,i.e. L part of L-T-P-C
        int visit_status=0;

    };

    data arr[150];

    arr[0].course_code="PC110";
    arr[0].type='c';
    arr[0].program="bi";
    arr[0].year=1;
    arr[0].credit=3;

    arr[1].course_code="PC110";
    arr[1].type='c';
    arr[1].program="bc";
    arr[1].year=1;
    arr[1].credit=3;

    arr[2].course_code="PC110";
    arr[2].type='c';
    arr[2].program="bm";
    arr[2].year=1;
    arr[2].credit=3;

    arr[3].course_code="PC110";
    arr[3].type='c';
    arr[3].program="be";
    arr[3].year=1;
    arr[3].credit=3;

    
    arr[4].course_code="EL111";
    arr[4].type='c';
    arr[4].program="bi";
    arr[4].year=1;
    arr[4].credit=3;

    arr[5].course_code="EL111";
    arr[5].type='c';
    arr[5].program="bc";
    arr[5].year=1;
    arr[5].credit=3;

    arr[6].course_code="EL111";
    arr[6].type='c';
    arr[6].program="be";
    arr[6].year=1;
    arr[6].credit=3;


    arr[7].type='c';
    arr[7].program="bi";
    arr[7].course_code="IC101";
    arr[7].year=1;
    arr[7].credit=1;

    arr[8].type='c';
    arr[8].program="bc";
    arr[8].course_code="IC101";
    arr[8].year=1;
    arr[8].credit=1;

    arr[9].course_code="IT112";
    arr[9].type='c';
    arr[9].program="bi";
    arr[9].year=1;
    arr[9].credit=3;

    arr[10].course_code="IT112";
    arr[10].type='c';
    arr[10].program="bc";
    arr[10].year=1;
    arr[10].credit=3;

    arr[11].course_code="IT112";
    arr[11].type='c';
    arr[11].program="be";
    arr[11].year=1;
    arr[11].credit=3;

    arr[12].course_code="SC107";
    arr[12].type='c';
    arr[12].program="bi";
    arr[12].year=1;
    arr[12].credit=3;

    arr[13].course_code="SC107";
    arr[13].type='c';
    arr[13].program="bc";
    arr[13].year=1;
    arr[13].credit=3;

    arr[14].course_code="MC111";
    arr[14].type='c';
    arr[14].program="bm";
    arr[14].year=1;
    arr[14].credit=3;

    arr[15].course_code="MC112";
    arr[15].type='c';
    arr[15].program="bm";
    arr[15].year=1;
    arr[15].credit=3;

    arr[16].course_code="MC116";
    arr[16].type='c';
    arr[16].program="bm";
    arr[16].year=1;
    arr[16].credit=1;

    arr[17].course_code="MC123";
    arr[17].type='c';
    arr[17].program="bm";
    arr[17].year=1;
    arr[17].credit=3;

    arr[18].course_code="ED111";
    arr[18].type='c';
    arr[18].program="be";
    arr[18].year=1;
    arr[18].credit=3;

    arr[19].course_code="ED112";
    arr[19].type='c';
    arr[19].program="be";
    arr[19].year=1;
    arr[19].credit=3;

    int ci=0,cc=0,ce=0,cm=0;


    for (int i = 0; i < 20; i++)

    {
        if(arr[i].program=="bi")
        {
            ci++;
        }

        else if (arr[i].program=="be")
        {
            ce++;
        }

        else if (arr[i].program=="bc")
        {
            cc++;
        }

        else 
        {
            cm++;
        }   
        
    }

    cout<<max({ci,cc,cm,ce});
    
    
    
    return 0;
}
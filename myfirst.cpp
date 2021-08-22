
#include <iostream>

#include <fstream>
#include <vector>
using namespace std;
int firstpage();
void choice(void);                                                                     //function declaration
void shuffle(int *arr, int z);
int header(int x);

inline int head();                                                                       //inline function

class student                                                                            //base class   (inheritance)
{

    string roll;
    string dob;
    float grade;

public:
    string name;
    student()                                                                               //default constructure
    {
        grade = 0;
    }
    void getdata(int i)                                                                     //To store student data in file  
    {    cin.ignore();
        cout << "(" << i << ")  Enter student name : ";
        getline(cin,name);
        cout << "     Enter roll no. : ";
        
        
        cin >> roll;
        cout << "     Enter date of birth(ddmmyyyy) : ";
        cin >> dob;

        ofstream fout;
        fout.open("student.txt", ios::app);
        fout << name << "|" ;
        fout<< roll << "|" ;
        fout<< dob << "|";
        fout.close();
    }

    int showgrade()
    {
        return grade;
    }
    string showrollno()
    {
        return roll;
    }
    string showname()
    {
        return name;
    }
    string showdob()
    {
        return dob;
    }
};

class teachverify : public student                                                      //derived class
{

    string passward;

public:
    teachverify(string g, string f)                                                   //perameterised constructor
    {

        name = g;
        passward = f;
    }
    int verify()                                                                                  //default username and passward of faculty
    {
        if ((name == "jaydeep" && passward == "12345") || (name == "patidar" && passward == "54321") || (name == "ram" && passward == "67890"))
        {
            return 1;
        }
        else
            return 0;
    }

    friend string teachname(teachverify A);                                             //friend function declaration
};

string teachname(teachverify A)                                                      //friend function defination
{
    return A.name;
}

class stuverify                                                            //student verification by reteriving data from file
{
private:
    string  password;
    int index;

public:
     string name,rollno;
    int loginverify()
    {
        int count = 0;
        cout << "                           STUDENT LOGIN \n\n\n";
        cout << "Enter Roll No. : ";
        cin >> rollno;
        cout << "Enter password(DOB ddmmyyyy) : ";
        cin >> password;
        ifstream fin;
        fin.open("student.txt", ios::in);
        char c = 'a';
        while (!fin.eof())
        {
            string s1 = "", s2 = "", s3="";

            c=fin.get();

            while ((c) != '|')
            {
               cout<<c;
               c=fin.get();
            }
          
            c=fin.get();
            while (c != '|')
            {
                s1 = s1 + c;

             c=fin.get();
            }
cout<<s1;
             c=fin.get();
            while (c != '|')
            {
                s2 = s2 + c;

                 c=fin.get();
            }
          

            c=fin.get();
            


            if (rollno == s1 && password == s2)
            {  
                fin.close();
                return 1;
            }
        }
        fin.close();
        
        return 0;
    }

    int knowstudent()
    {
        return index;
    }
};

class question                                                                              //read and write data in file
{
    string que, op1, op2, op3, op4;
    float maxmarks, marks;
    int correctans;

public:
  
    void setquestion(int i)
    {
        cin.ignore();
        ofstream fout;
        fout.open("question.txt", ios::app);
        cout << "# enter question (" << i << ")\n ";

        getline(cin, que);
        fout << que << "|";
        cout << "\n  enter option 1\n";
        getline(cin, op1);
        fout << op1 << "|";
        cout << "\n  enter option 2\n";
        getline(cin, op2);
        fout << op2 << "|";
        cout << "\n  enter option 3\n";
        getline(cin, op3);
        fout << op3 << "|";
        cout << "\n  enter option 4\n";
        getline(cin, op4);
        fout << op4 << "|";
        fout.close();
    }

    void setmaxmarks()
    {
        ofstream fout;
        fout.open("marks.txt", ios::app);
        cout << "enter marks for this question(integer) : ";
        cin >> maxmarks;
        fout << maxmarks;
        cout << endl;
        fout.close();
    }

    void setcorrectans()
    {
        ofstream fout;
        fout.open("corrans.txt", ios::app);
        cout << "\n\nenter correct option(integer) : ";
        cin >> correctans;
        fout << correctans;
        cout << endl;
        fout.close();
    }

    char displayque(ifstream &fin,char c)
    {
       
        
        string s1 = "", s2 = "", s3 = "", s4 = "", s5 = "";

        while (c != '|')
        {
            s1 = s1 + c;
            c = fin.get();
        }
        cout << endl
             << endl
             << s1 << endl
             << endl;
        c = fin.get();
        while ((c != '|'))
        {
            s2 = s2 + c;
            c = fin.get();
        }
        c = fin.get();
        while ((c != '|'))
        {
            s3 = s3 + c;
            c = fin.get();
        }
        c = fin.get();
        while ((c != '|'))
        {
            s4 = s4 + c;
            c = fin.get();
        }
        c = fin.get();
        while ((c != '|'))
        {
            s5 = s5 + c;
            c = fin.get();
        }
      c=fin.get();
        cout << "1 :- " << s2 << endl;
        cout << "2 :- " << s3 << endl;
        cout << "3 :- " << s4 << endl;
        cout << "4 :- " << s5 << endl;
        return c;
    }

    int returnans()
    {
        return correctans;
    }
    float returnmarks()
    {
        return maxmarks;
    }

    
};



int main()                                                                           //main function starts
{
    int y;
    int z;
    int set1 = 0;
    int set2 = 0;
    float Mark = 0;
    question *q;
    student *p;
above:
top:
    system("cls");

    switch (head()) 
    {
    case 1:
    {
        system("cls"); 
        cout << "\n------------------------------------------------------\n";
        cout << "                     FACULTY LOGIN      \n";
        cout << "\n------------------------------------------------------\n";
        cout << " \n Enter your USERNAME : ";
        string m;
        string l;
        cin >> l;
        cout << " \n Enter PASSWARD : ";
        cin >> m;
        cout << "\n\n";
        teachverify a1(l, m);                                                               //use of perameterised constructor
        int v = a1.verify();
        if (v == 1)
        {
        ggg:
            system("cls");
            cout << "\n\n----------------------------------------------------------------\n";
            cout << "                #FACULTY >> " << teachname(a1) << "\n\n\n";                //calling friend function
            cout << "----------------------------------------------------------------\n";

            int aaa;

            cout << "Enter 1 ADD STUDENT\n";
            cout << "Enter 2 TO SET QUESTION PAPER\n";
            cout << "Enter 3 TO GO BACK\n";
            cout << "Enter 0 TO EXIT\n";
            cin >> aaa;
            switch (aaa)
            {
            case 1:
            {
                system("cls");
                cout << "\n\n----------------------------------------------------------------\n";
                cout << "                 #STUDENT MANAGEMENT\n\n\n";
                cout << "----------------------------------------------------------------\n";
                cout << "faculty >> " << teachname(a1) << "\n\n\n";
                cout << "enter the number of student which you want to add: ";
                cin >> y;
                cout << "\n\n";
                p = new student[y]; 
                for (int i = 0; i < y; i++)
                {

                    p[i].getdata(i + 1); 
                    cout << endl;
                }
                goto ggg;
            }
            case 2:
            {
                system("cls");
                cout << "\n\n---------------------------------------------------------------------\n";
                cout << "                          # SET QUESTIONS FOR TEST \n";
                cout << "-----------------------------------------------------------------------\n";
                cout << "faculty >> " << teachname(a1) << "\n\n\n";
                
                cout << " Enter number of question which you want to add : ";
                cin >> z;
                cout << "\n\n";

                q = new question[z]; 
                for (int i = 0; i < z; i++)
                {
                    q[i].setquestion(i + 1); 
                    q[i].setcorrectans();
                    q[i].setmaxmarks();
                    cout << "\n\n";
                }
                set1 = 1;
            }
            case 3:
            {
                goto top;
            }
            case 4:
            {
                return 0;
            }
            default:
                cout << "invalid choice";
            }
        }
        else
            cout << " Invalid Name or passward\n";
    up:
        cout << " # Enter 0 to EXIT \n";
        cout << " # Enter 1 for HOME PAGE \n ";
        int r;
        cin >> r;
        if (r == 0)
            goto end;
        else if (r == 1)
            goto top;
        else
            goto up;

        break;
    }
    case 2:
    {
        system("cls");
        ifstream fin;
        fin.open("question.txt",ios::in);
        char cs;
        fin>>cs;
        if (fin.eof())
        {  fin.close();
            cout << "\n\n\n--------------------------------------------------------------\n";
            cout << "                  TEST NOT YET STARTED  \n";
            cout << "--------------------------------------------------------------\n\n\n";
        }

        else
        {
            fin.close();
            stuverify a2;
            int v = a2.loginverify(); //to verify student login
            if (v != 0)
            {
                system("cls");

                int s = a2.knowstudent(); 
                header(1);
                
                cout << "             -----------------------------------------------------------------------\n";
                cout << "\n                                  ROLL NO : " << a2.rollno << "\n"; 
                cout << "                          -------------------------------------------\n";
                cout << "                                              QUIZ                                       \n";
                cout << "                          -------------------------------------------\n\n\n";
                float marks;
                class question q;

                vector<int> num; //another array

                ifstream fin;
                fin.open("question.txt", ios::in);
                char c=' ';
                while (!fin.eof())
                {
                    int xx;

                    c=q.displayque(fin,c); 
                    cin >> xx;
                    num.push_back(xx); 
                }
                fin.close();
                system("cls");
                float totalmarks = 0,tm=0;
                fstream fin1;
                fin1.open("marks.txt",ios::in);
                fstream fin2;
                fin2.open("corrans.txt",ios::in);
                for (int i = 0; i < num.size(); i++) //calculate marks
                {  
                    
                    char ch1,ch2;fin2>>ch1;
                    fin1>>ch2;
                    int v=(int)ch1-48;int vv=(int)ch2-48;
                    cout<<v<<" "<<vv;
                     if(v==num[i])
                    totalmarks = totalmarks + vv;
                    cout<<totalmarks;
                    tm=tm+vv;
                    cout<<tm;
                }
                fin1.close();
                header(1);
                cout << "\n\n\n                              Total marks obtained in test is " << totalmarks << " out of " << tm << "\n\n\n\n";
            }
            else
            {
                cout << " invalid rollno or Password";
            }
        }
    upp:
        cout << "\n\n\nEnter 0 to EXIT \n";
        cout << "Enter 1 for HOME PAGE \n ";
        int r;
        cin >> r;
        if (r == 0)
            goto end;
        else if (r == 1)
            goto top;
        else
            goto upp;

        break;
    }
    case 0:
    {
    end:
        system("cls");

        cout << " \n\n\n     press ENTER to EXIT\n\n\n";
        return 0;
    }

    default:
    {
        system("cls");
        cout << "invalid choice\n\n";
        goto above;
    }
    }
}

int head() 
{

    int a;
    header(1); 
    cout << "\n   1:Faculty Login\n";

    cout << "   2:Student Login\n";

    cout << "   press 0 to Exit\n";
    cin >> a;
    return a;
}



int header(int x)
{
    cout << "\n\n\n                           NATIONAL INSTITUTE OF TECHNOLOGY                       \n";
    cout << "                                        WARANGAL                      \n\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "                                      EXAMINATION\n";
    cout << "-----------------------------------------------------------------------------------------\n";
}

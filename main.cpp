#include <iostream>

using namespace std;
enum _month{January,February,March,April,May,June,July,August,September,October,November,December};
_month d_month(int month)
{
    return _month(month);
}
void print_month(_month pM,int year)
{
    switch(pM){
    case January: cout<<"January"<<" "<<year<<endl;     break;
    case February:cout<<"February"<<" "<<year<<endl;    break;
    case March:   cout<<"March"<<" "<<year<<endl;       break;
    case April:   cout<<"April"<<" "<<year<<endl;       break;
    case May:     cout<<"May"<<" "<<year<<endl;         break;
    case June:    cout<<"June"<<" "<<year<<endl;        break;
    case July:    cout<<"July"<<" "<<year<<endl;        break;
    case August:  cout<<"August"<<" "<<year<<endl;      break;
    case September:cout<<"September"<<" "<<year<<endl;  break;
    case October:cout<<"October"<<" "<<year<<endl;      break;
    case November:cout<<"November"<<" "<<year<<endl;    break;
    case December:cout<<"December"<<" "<<year<<endl;    break;
    }
}
int DiaSemana (int d, int m, int y) {

  int z, a, b, c;

    if (m <= 2) {
        a = m + 10 ;
        b = (y - 1) % 100;
        c = (y - 1) / 100;
    } else if (m >= 3) {
        a = m - 2;
        b = y % 100;
        c = y / 100;
    }

    z = (700 + (26 * a - 2) / 10 + d + b + b / 4  + c / 4 - 2 * c - 1) % 7;
    return z;
}
int c_days(_month ds,int year)
{
    switch(ds){
    case January:  return 31;
    case February:
        if(year%100==0 && year%400!=0)
        {
            return 28;
        }
        if(year%4==0)
        {
            return 29;
        }
        return 28;

    case March:   return 31;
    case April:   return 30;
    case May:     return 31;
    case June:    return 30;
    case July:    return 31;
    case August:  return 31;
    case September:return 30;
    case October:return 31;
    case November:return 30;
    case December:return 31;
    }

}
void print_date(int day,int month,int year)
{
    print_month(d_month(month-1),year);
    cout<<"SU"<<" "<<"MO"<<" "<<"TU"<<" "<<"WE"<<" "<<"TH"<<" "<<"FR"<<" "<<"SA"<<endl;
    int days[6][7];
        for(int i=0;i<6;++i)
        {
            for(int j=0;j<7;++j)
            {
                days[i][j]=0;
            }
        }
    int firsD=(DiaSemana(1,month,year))+1;
    int c=1;
    int lim=(c_days(d_month(month-1),year))+1;
    if(firsD==7)
    {
        firsD=0;
    }
        for(int i=0;i<6;++i)
        {
            for(int j=0;j<7;++j)
            {
                if(c==1)
                {
                    j=firsD;
                }
                days[i][j]=c;
                ++c;
                if(c==lim)
                {
                    break;
                }
            }
            if(c==lim)
            {
                break;
            }
        }
         for(int i=0;i<6;++i)
        {
            for(int j=0;j<7;++j)
            {
                if(days[i][j]!=0)
                {
                    cout<<days[i][j];
                }

                if(days[i][j]==0)
                {
                    cout<<" ";
                }
                if(days[i][j]<10)
                {
                    cout<<"  ";
                }
                else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }


}
int main()
{
   int days,month,year;
   cout<<"ingrese el dia"<<endl;
   cin>>days;
   cout<<"ingrese el mes"<<endl;
   cin>>month;
   cout<<"ingrese el año"<<endl;
   cin>>year;
    print_date(days,month,year);

    return 0;
}

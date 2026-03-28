#include <iostream>
using namespace std;
class Time{
    private:
    int hour ;
    int mins ; 
    int second;
    int alaram_hour;
    int Alaram_min ; 
    int Alaram_sec;
    static int total_Alaram;
    public:
    Time(int = 0 , int = 0 , int = 0);
    Time&setTime(int , int , int);
    Time&sethour(int);
    Time&setmin(int);
    Time&setsec(int);
    Time&setAlaramtime(int , int , int);
    Time&setalaramhour(int);
    Time&setalarammin(int);
    Time&setAlaramsec(int);
    int gethour() const;
    int getmin()const;
    int getsec() const;
    int getalaramhour()const;
    int getalarammin()const;
    int getalaramsec()const;
    void printalaram()const;
    void printstandardformat() const;
};
int Time::total_Alaram = 0;
Time&Time::setalaramhour(int hr){
    this -> alaram_hour = ((hr >= 0 && hr <=23)? hr : 0);
    return *this;
}
Time&Time::setalarammin(int min){
    this -> Alaram_min = ((min >= 0 && min <=59)? min : 0);
    return *this;
}
Time&Time::setAlaramsec(int sec){
    this -> Alaram_sec = ((sec >= 0 && sec <=59)? sec : 0);
    return *this;
}
int Time::getalaramhour()const{
    return alaram_hour;
}
int Time::getalarammin()const{
    return Alaram_min;
}
int Time::getalaramsec()const{
    return Alaram_sec;
}
Time::Time(int hr , int min , int sec){
    setTime(hr , min , sec);
}
Time&Time::setTime(int h , int m ,int sec){
    sethour(h);
    setmin(m);
    setsec(sec);
    return *this;
}
Time&Time::sethour(int h){
    this -> hour = ((h >=0 && h <= 23)? h : 0);
    return *this;
}
int Time::gethour() const{
    return hour;
}
Time&Time::setmin(int m){
    this -> mins = ((m >= 0 && m <=59)? m : 0);
    return *this;
}
int Time::getmin() const{
    return mins;
}
Time&Time::setsec(int sec){
    this ->second = ((sec>=0&&sec <=59)?sec: 0);
    return *this;
}
int Time::getsec() const{
    return second;
}
void Time::printstandardformat()const {
        cout <<((hour == 0 || hour ==12)? 12 : hour%12)<<":" <<((mins<10)?"0":"")<<mins<<":"<<((second<10)?"0":"")<<second<<((hour<12)?" AM":" PM")<<endl;
}    
void Time::printalaram()const{        
    total_Alaram++;
    cout <<((alaram_hour == 0 || alaram_hour ==12)? 12 : alaram_hour%12)<<":" <<((Alaram_min<10)?"0":"")<<Alaram_min<<":"<<((Alaram_sec<10)?"0":"")<<Alaram_sec<<((alaram_hour<12)?" AM":" PM")<<endl;
    cout << "You set alaram for "<<total_Alaram<<endl;
}
int main(){
    int button;
    do
    {
        int hour;
        int min;
        int sec;
        int alaramhr;
        int alarammin;
        int alaramsec;
        cout << "Enter 1 to show time"<<endl;
        cout << "Enter 2 to set Alaram"<<endl;
        cout << "Enter 3 to exit"<<endl;
        cin >> button;
        if (button == 1){
            cout << "Enter the hour: ";
            cin >> hour;
            cout << "Enter the mins: ";
            cin >> min;
            cout << "Enter the seconds: ";
            cin >> sec;
            Time s;
            s.sethour(hour).setmin(min).setsec(sec).printstandardformat();
        }
        else if (button==2){
            int alaramsize;
            cout << "how many alaram do u want to set? "<<endl;
            cin >> alaramsize;
            Time*arr = new Time [alaramsize];
            for (int i = 0 ; i < alaramsize ; i++){
            cout << "Enter the hour: ";
            cin >> alaramhr;
            cout << "Enter the mins: ";
            cin >> alarammin;
            cout << "Enter the seconds: ";
            cin >> alaramsec;
                arr[i].setalaramhour(alaramhr).setalarammin(alarammin).setAlaramsec(alaramsec).printalaram();
            }
            delete [] arr;
            arr = nullptr;
        }
        else if (button==3){
            break;
        }
        else{
            cout << "Invalid."<<endl;
        }
    } while (button!=3);
    
}
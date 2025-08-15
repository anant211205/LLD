#include <bits/stdc++.h>
using namespace std; 

// strategies class for talk
class Talkable{
    public:
        virtual void talk() = 0 ;
        virtual ~Talkable() {} ;
};

class NormalTalk : public Talkable{
    public :
        void talk(){
            cout<<"Normal Talk..."<<endl ;
        }
};

class NoTalk : public Talkable{
    public:
        void talk(){
            cout<<"No Talk..."<<endl;
        }
};

// strategies class for walk
class Walkable{
    public:
        virtual void walk() = 0 ;
        virtual ~Walkable() {} ;
};

class NormalWalk : public Walkable{
    public:
        void walk(){
            cout<<"Normal Walk..."<<endl ;
        }
};
class NoWalk : public Walkable{
    public:
        void walk(){
            cout<<"No Walk..."<<endl ;
        }
};

// strategies class for fly
class Flyable{
    public:
        virtual void fly() = 0 ;
        virtual ~Flyable() {} ;
};

class NormalFly : public Flyable{
    public: 
        void fly(){
            cout<<"Normal Fly..."<<endl;
        }
};

class NoFly : public Flyable{
    public: 
        void fly(){
            cout<<"No Fly..."<<endl;
        }
};

class Projection{
    public:
        virtual void projection() = 0 ;
        virtual ~Projection() {} ;
};  

class FullProjection : public Projection{
    public:
        void projection(){
            cout<<"Full Projection..."<<endl;
        }
};

class HalfProjection : public Projection{
    public :
        void projection(){
            cout<<"Half Projection..."<<endl;
        }
};

class Robot{
    protected:
        Flyable* f ;
        Talkable* t; 
        Walkable* w;
        Projection* p;

    public:
        void talk(){
            t->talk() ;
        }
        void walk(){
            w->walk() ;
        }
        void fly(){
            f->fly() ;
        }
        void project(){
            p->projection();
        }
};

class CompanionRobot : public Robot{
    public:
        CompanionRobot(Flyable*f,Talkable*t,Walkable*w,Projection*p){
            this->f = f ;
            this->t = t;
            this->w = w ;
            this->p = p ;
        }
};

class WorkerRobot : public Robot{
    public:
        WorkerRobot(Flyable*f,Talkable*t,Walkable*w,Projection*p){
            this->f = f ;
            this->t = t;
            this->w = w; 
            this->p = p;
        }
};

int main(){

    Robot*robot1 = new CompanionRobot(new NoFly() , new NormalTalk() ,new NormalWalk(),new FullProjection()) ;
    robot1->fly();
    robot1->talk();
    robot1->walk();
    robot1->project();

    cout<<"--------------------------"<<endl;

    Robot*robot2 = new WorkerRobot(new NormalFly() , new NoTalk(), new NoWalk() , new HalfProjection()) ;
    robot2->fly();
    robot2->talk();
    robot2->walk();
    robot2->project();

    return 0;
}
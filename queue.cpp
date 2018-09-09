#include<iostream>
using namespace std;
#define max_size 101
class queue_{
        int que[max_size];
        int frnt,rear;
    public:
        queue_(){
            frnt=-1;
            rear=-1;
        }
        bool isempty(){
            return (frnt ==-1&& rear==-1);
        }
        bool isfull(){
            return (rear+1)%max_size==frnt?true:false;
        }
        void enqueue(int x){
            if (isfull()){
                cout<<"Sorry, Bro queue is already full!"<<endl;
                return;
            }
            if (isempty()){
                frnt=rear=0;
            }
            else{
                    rear=(rear+1)%max_size;
            }
            que[rear]=x;
            cout<<x<<" is added to queue succesfully"<<endl;
        }
        void dequeue(){
            if(isempty()){
                cout<<"Sorry, Bro u can't remove  anything from empty queue!"<<endl;
                return;
            }
            if(frnt==rear){
                cout<<"Successfully deleted "<<que[frnt]<<"!"<<endl;
                frnt=rear=-1;
            }
            else{
                cout<<"Successfully deleted "<<que[frnt]<<"!"<<endl;
                frnt=(frnt+1)%max_size;
            }
        }
        int frnt_(){
            if(isempty()){
                cout<<"Sorry, Bro queue is empty!"<<endl;
                return -1;
            }
            else
                return que[frnt];
        }
        void print(){
            if(isempty()) return;
            int cnt=(rear-frnt+max_size)%max_size+1;
            for(int i=0;i<cnt;i++){
                cout<<que[(frnt+i)%max_size]<<" ";
            }
            cout<<endl;
        }
        void menu();
};
int main(){
    queue_ q;
    q.menu();
    /*q.enqueue(5);
    q.print();
    q.enqueue(3);
    q.print();
    q.enqueue(7);
    q.enqueue(6);
    q.print();
    cout<<q.frnt_()<<endl;
    q.dequeue();
    q.print();
    cout<<q.frnt_()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.frnt_()<<endl;
    q.dequeue();
    q.dequeue();
    //cout<<q.frnt_()<<endl;*/
    return 0;
}
void queue_::menu(){
    cout<<endl<<"What would u like to perform: "<<endl<<"1. Check Queue Empty"<<endl<<"2. Check Queue Full"<<endl
    <<"3. Check Front of Queue"<<endl<<"4. Print Queue"<<endl<<"5. Enqueue"<<endl<<"6. Dequeue"<<endl;
    int dec;
    cin>>dec;
    switch(dec){
        case 1: if(isempty()==1) cout<<"True"<<endl;
                else cout<<"False"<<endl;
                menu();
                break;
        case 2: if(isfull()==1) cout<<"True"<<endl;
                else cout<<"False"<<endl;
                menu();
                break;
        case 3: if(frnt_()!=-1) cout<<frnt_()<<endl;
                menu();
                break;
        case 4: cout<<endl<<"Queue: ";
                print();
                cout<<endl;
                menu();
                break;
        case 5: int x;
                cout<<"Enter value u want to add to queue: ";
                cin>>x;
                enqueue(x);
                menu();
                break;
        case 6: dequeue();
                menu();
                break;
    }
}

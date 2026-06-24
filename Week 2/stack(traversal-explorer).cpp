#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    template<typename T>
    class Stack{
        vector<T> s;
        public :
        Stack(){}
        void push(const T& value){
            s.push_back(value);
        }
        Stack(initializer_list<T> list){
            for(const T& x : list){
                s.push_back(x);
            }
        }
        void pop(){
            if(s.size() == 0){
                throw underflow_error("Stack is empty");
            }
            s.pop_back();
        }
        T& top(){
            if(s.size() == 0){
                throw runtime_error("Stack is empty");
            }
            return s.back();
        }
        const T& top() const{
             if(s.size() == 0){
                throw underflow_error("Stack is empty");
            }
            return s.back();
        }

        bool empty() const{
            if(s.size() == 0) return true;
            else return false;
        }
        size_t size() const{
            return s.size();
        }
        ~Stack(){
            while(s.size() > 0){
                pop();
            }
        }
        bool operator==(const Stack& ss) const{
            return s == ss.s;
        }
        bool operator!=(const Stack& ss) const{
            return s != ss.s;
        }
        friend ostream& operator<<(ostream& cout, const Stack& st){
            cout<<"[";
            for(int i = (int)st.s.size() - 1; i >= 0; i--){
                cout<<st.s[i];
            if(i > 0) cout<<", ";
           }
            cout<<"]";
            return cout;
        }
    };

int main(){
        return 0;
}
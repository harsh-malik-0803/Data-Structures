class student{
    public: 
    int rollno;
    private: 
    int age;
    public: 
    void display(){
        cout<<age<<" "<<rollno<<endl;
    }
    int getage(){
        return age;
    }
    void setage (int a,int password){
        if(password!=123){
            return;
        }
        if(a<0)
        return ;

        age=a;
    }

};
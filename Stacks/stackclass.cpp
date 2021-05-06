// using array and dynamic array

template<typename T>
class stackusingarray{
   public:
   T * data;
   int nextindex;
   int capacity;

   stackusingarray(){
      data=new T[4];
      nextindex=0; 
      capacity =4;
   }
   void push(T element){
      if(nextindex==capacity){
         T* newdata=new T[2*capacity];
         for(int i=0;i<capacity;i++){
            newdata[i]=data[i];
         }
         capacity*=2;
         data = newdata;
         delete [] data;
        /* cout<<"Stack is full "<<endl;
         return ;*/
      }
      data[nextindex]=element;
      nextindex++;
   }
   int size(){
      return nextindex;
   }
   bool isEmpty(){
      if(nextindex==0){
         return 1;
      }
      return 0;
   }
   T pop(){
      if(nextindex==0){
         cout<<"stack is empty"<<endl;
         return 0;
      }
      nextindex--;
      return data[nextindex];
   }
   T top(){
      if(nextindex==0){
         cout<<"stack is empty"<<endl;
         return 0;
      }
      return data[nextindex-1];
   }
};
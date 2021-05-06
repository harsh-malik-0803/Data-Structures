class fraction{
    private:
    int numerator;
    int denominator;
    public:
    
    fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print(){
        cout<<numerator<<"/"<<denominator<<endl;
    }
    void simplify(){
        int gcd=1;
        for(int i=0;i<min(numerator,denominator);i++){
            if(numerator%i==0 && denominator%i==0){
                gcd=i;
            }
        }
        numerator=numerator/gcd;
        denominator/=gcd;
    }
    void add(fraction f2){
        int lcm=denominator*f2.denominator;
        int num=f2.denominator*numerator+denominator*f2.numerator;
        numerator=num;
        denominator=lcm;
        simplify(); 
    }

};
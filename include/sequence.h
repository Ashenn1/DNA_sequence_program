#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<cstring>
#include<iomanip>
#include<fstream>
class sequence
{
    public:
        sequence(){}
        sequence(int length){}
        virtual ~sequence();
        sequence( sequence& rhs);
       virtual void setseq(char*sequence);
        virtual char*getseq();
        virtual void print()=0;
        virtual void loadsequencefromfile(char*filename)=0;
        virtual void savesequencetofile(char*filename)=0;
       friend char* Align(sequence* s1,sequence *s2);


//       virtual bool operator==(sequence &lhs,sequence &rhs{});
//       virtual bool operator!=(sequence &lhs,sequence &rhs){};
//       virtual sequence operator+(sequence &lhs ,sequence &rhs){};
    protected:
          char* seq;

    private:
};
//friend sequence* Align(sequence* s1,sequence *s2);
#endif // SEQUENCE_H

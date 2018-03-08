#ifndef DNA_H
#define DNA_H
#include<iomanip>
#include<fstream>
#include <sequence.h>
#include"RNA.h"
using namespace std;
class RNA;
enum DNA_Type{promoter,motif,tail,noncoding};

class DNA : public sequence
{
    public:
        DNA();
        DNA(char*sequence,DNA_Type atype);
        DNA(const DNA& rhs);//copy constructor
        const DNA operator=(const DNA &rhs);//assignment operator
        void print();
        void setseq(char*sequence);
        char*getseq();
        RNA converttoRNA ();
        void buildcomplementarystrand();
         void loadsequencefromfile(char*filename);
        friend istream &operator >> (istream &, DNA &);
         void savesequencetofile(char*filename);
           bool operator==(DNA &rhs);
            bool operator!=(DNA &rhs);
            DNA operator+( DNA &rhs);
   bool Invalid_sequence(char *s);
         virtual ~DNA();


    protected:

    private:
        DNA_Type type;
        DNA *complementary_strand;
        int startchar;
        int endchar;
};

#endif // DNA_H

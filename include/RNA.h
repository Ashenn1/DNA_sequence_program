#ifndef RNA_H
#define RNA_H
#include<iomanip>
#include<fstream>
#include<iostream>
#include<sequence.h>
#include"protein.h"
#include"CodonsTable.h"
#include"DNA.h"
using namespace std;
enum RNA_Type{mRNA,tRNA,rRNA};
class DNA;
class protein;
class RNA : public sequence
{
    private:
        RNA_Type type;
        int startchar;
        int endchar;

    public:
        RNA();
        RNA(char*seq,RNA_Type atype);
        virtual ~RNA();
        //RNA(const RNA& rhs);
        void print();
        void setseq(char*sequence);
        char*getseq();
        protein ConvertToProtein(const CodonsTable& table);//ha3araf struct fl main bno3 codon yshel mn el seq talatat w ab3ato lel function dih
        DNA ConvertToDNA();
         void loadsequencefromfile(char*filename);
         void savesequencetofile(char*filename);
         friend istream &operator >>(istream &, RNA &);
         bool operator==(RNA &rhs);
            bool operator!=(RNA &rhs);
           RNA operator+(RNA &rhs);

    protected:

};


#endif // RNA_H

#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include<cstring>
#include<fstream>
class protein;
//struct representing a codon of 3 DNA/RNA characters and '\0'
struct codon
{
    char value[3];//0,1,2 and 3 for '\0';
    char AminoAcid;
};

class CodonsTable
{
   private:
       codon codons[64];// from 0 till 63, means their are 64 codons.

    public:
        CodonsTable();
        virtual ~CodonsTable();
        void loadcodonsfromfile(char* filename);
        codon getaminoacid(char*value) const ;// takes a value of 3 characters and returns their aminoacid char form
        void setcodon(char*value,char AminoAcid,int index);


};

#endif // CODONSTABLE_H

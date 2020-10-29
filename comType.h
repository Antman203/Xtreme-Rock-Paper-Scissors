#ifndef COMTYPE_H
#define COMTYPE_H
class comType
{
public:
    void go();
    char getSelection() const;
private:
    char selection;
    int count = 0;
};

#endif
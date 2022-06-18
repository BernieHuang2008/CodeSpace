#ifndef GDEFINE_H
#define GDEFINE_H

#define gout cout
#define gin cin
#define gerr cerr
#define glog clog

ostream& operator>>(istream& in,ostream& out){string s;in>>s;out<<s;return out;}

#endif

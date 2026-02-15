#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

    bool parseBoolExpr(string expression) {
        stack<char> ch;
        stack<char> op;
        vector<char> ev;

        for(int i=0; i<expression.size(); i++){
            if(expression[i] == '(') ch.push('m');

            else if(expression[i] == '&' || expression[i] == '|' || expression[i] == '!' ){
                op.push(expression[i]);
            }

            else if(expression[i] == ',') continue;

            else if(expression[i] == ')'){
                if(op.top() != '!'){
                    char result = (op.top() == '&') ? 't' : 'f'; 
                    while(ch.top() != 'm'){
                        ev.push_back(ch.top());
                        ch.pop();
                    }
                    ch.pop(); //pops 'm'
                    char oper = op.top();
                    op.pop();
                    if(oper == '&'){
                        for(int j=0; j<ev.size(); j++) if(ev[j] == 'f'){
                            result = 'f';
                            break;
                        }
                    }
                    else if(oper == '|'){
                        for(int j=0; j<ev.size(); j++) if(ev[j] == 't'){
                            result = 't';
                            break;
                        } 
                    }
                    ch.push(result);
                    ev.clear();
                }
                else{
                    op.pop();
                    char val = ch.top();
                    ch.pop();
                    ch.pop();
                    ch.push(val == 't' ? 'f' : 't' );
                }
                
            }
            else{
                ch.push(expression[i]);
            }

        }
        return ch.top() == 't';
    }

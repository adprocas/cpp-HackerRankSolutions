#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

queue<string> tagLines;
vector<string> queryLines;

vector<string> explode(const string& str, const char& ch) {
    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
         result.push_back(next);
    return result;
}

class Tag {
private:
    string name;
    vector<Tag*> subtags;
    map<string, string> attributes;
    
public:
    Tag() { 
    }
    
    void setName(string n) {
        name = n;
    }
    
    void setAttributes(map<string, string> attribs) {
        attributes = attribs;
    }
    
    void setSubTags(vector<Tag*> stags) {
        subtags = stags;
    }
    
    string getName() {
        return name;
    }
    
    map<string, string> getAttributes() {
        return attributes;
    }
    
    vector<Tag*> getSubTags() {
        return subtags;
    }
    
    void printSubtags(string pre) {
        
        cout << pre << "attributes for " << name << endl;
        
        for(auto p : attributes) {
            cout << pre << p.first << " " << p.second << endl;
        }
        
        cout << "subtags for " << name << endl;
        
        for(Tag* t : subtags) {
            cout << pre << pre << " --tag-- " << t->getName() << endl;
                        
            t->printSubtags("--" + pre);
        }
    }
};

void addAttributes(string line, Tag* headTag);

void addTags(Tag* headTag) {
    if(tagLines.size() > 0) {
        string line = tagLines.front();
        tagLines.pop();

        if(line.substr(1, 1) != "/") {
            Tag* newTag = new Tag();

            addAttributes(line, newTag);

            vector<Tag*> tags = headTag->getSubTags();
            tags.push_back(newTag);
            headTag->setSubTags(tags);

            int level = 0;
            while(tagLines.size() > 0) {
                line = tagLines.front();

                if(line.substr(1, 1) != "/") {
                    level++;
                    addTags(newTag);
                } else {
                    --level;
                    if(level < 0) {
                        break;
                    }
                    
                    addTags(headTag);
                }
            }
        }

        if(tagLines.size() > 0 && line.substr(1, 1) != "/") {
            addTags(headTag);
        }
    }
}

void addAttributes(string line, Tag* headTag) {
    int currentPos = 1;
    int start = 1;
    //find the first <>
    //go through attributes
    //see if it has children - if so, recursive add
    //I don't think I really need to bother with the closing tags here
    //acutally, I might need to
    
    int y = 0;
    bool attributeValue = false;
    map<string, string> attrs;
    string tmpAttrName;
    string previousToken;
    
    for(;;) {
        string token;

        //nothing left
        if(line.length() < 1) {
            break;
        } else if(line.find(' ') == std::string::npos) {//no more attributes to parse
            currentPos = line.length();
            token = line.substr(start, line.length()-1);
        } else {//parse the attribute
            currentPos = line.find(' ') + 1;
            token = line.substr(start, line.find(' '));
        }

        line.erase(0, currentPos);


        if(y == 0) {
            headTag->setName(token.substr(0, token.length()-1));
            attributeValue = false;
        } else if(token == "=") {
            attributeValue = true;
            tmpAttrName = previousToken;
        } else if(attributeValue == true) {
            attributeValue = false;
            attrs.insert(make_pair(tmpAttrName, token.substr(1, token.length()-2)));
        } else {
            attributeValue = false;
        }

        previousToken = token;

        start = 0;

        ++y;
    }

    
    headTag->setAttributes(attrs);
}

string getNode(string name, Tag* head) {
    vector<string> attribute = explode(name, '~');
    vector<string> tagWalk = explode(attribute.at(0), '.');
        
    bool foundWalk = true;
    
    vector<Tag*> nodeList;
    nodeList = head->getSubTags();
    Tag* node;
    bool foundFirst = false;
    
    for(string tag : tagWalk) {
        bool found = false;
        
        //I'm not iterating all of the nodes here
        //I need to
        if(foundFirst == false) {
            for(Tag* t : nodeList) {
                string name = t->getName();
            
                if(name == tag) {
                    node = t;
                    
                    foundFirst = true;
                    
                    break;
                }
            }
        } else {
            bool findNext = false;
            
            for(Tag* t : node->getSubTags()) {
                string name = t->getName();
                
                if(strcmp(name.c_str(), tag.c_str()) == 0) {
                    findNext = true;
                    
                    node = t;
                    
                    break;
                }
            }
            
            if(!findNext) {
                foundWalk = false;
                break;
            }
        }
        
        if(foundFirst == false) {
            foundWalk = false;

            break;
        }
    }
    
    
    
    if(foundWalk == true) {
        map<string, string> myMap = node->getAttributes();
        std::map<string,string>::iterator it = myMap.find(attribute.at(1));
        
        if (it != myMap.end()) {
            return it->second;
        }
    }
    
    return "Not Found!";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n, q;
    
    cin >> n >> q;
    string dumb;
    getline(cin, dumb);
    
    for(int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        tagLines.push(line);
    }
    
    for(int i = 0; i < q; ++i) {
        string line;
        getline(cin, line);
        queryLines.push_back(line);
    }
    
    Tag* headTag = new Tag();
    headTag->setName("base");
    
    while(tagLines.size() > 0) {
        addTags(headTag);
    }
    
    for(string line : queryLines) {
        string nodeString = getNode(line, headTag);
        
        if(nodeString != "") {
            cout << nodeString << endl;
        }
    }
    
    //headTag->printSubtags("--");
    
    return 0;
}
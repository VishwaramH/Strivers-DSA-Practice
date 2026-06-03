class Solution:
    def __init__(self):
        self.st = []
        self.top = -1


    def isValid(self, s: str) -> bool:
        if len(s) == 1:
            return False
        for i in range(len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                self.st.append(s[i]) 
                self.top += 1
            
            elif s[i] == ')' or s[i] == '}' or s[i] == ']':
                if s[i] == ')':
                    if '(' in self.st and self.st[self.top] == '(':
                        self.st.pop()
                        self.top -= 1
                    else:
                        return False
                
                if s[i] == '}':
                    if '{' in self.st and self.st[self.top] == '{':
                        self.st.pop()
                        self.top -= 1
                    else:
                        return False

                if s[i] == ']':
                    if '[' in self.st and self.st[self.top] == '[':
                        self.st.pop()
                        self.top -= 1
                    else:
                        return False
        
        if self.top == -1:
            return True
        return False
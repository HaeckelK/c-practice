import re

with open("demo.jo", "r") as f:
    lines = f.readlines()

output = """#include <stdio.h>
#include <assert.h>

#include "list.h"

int main() {
    printf("Hello cats\\n");
    CONTENT
}
"""

content = []

print("Transpiler START")

for line in lines:
    print(line)

    transpiled = None

    if matches:=re.findall(r"declare ([\w]+) ([\w]+)", line):
        transpiled = f"{matches[0][0]} *{matches[0][1]} = new_list();"
    elif matches:=re.findall(r"([\w]+) = \[(\d+)\]", line):
        transpiled = f"append({matches[0][0]}, {matches[0][1]});"
    elif matches:=re.findall(r"([\w]+).add\((\d+)\)", line):
        transpiled = f"append({matches[0][0]}, {matches[0][1]});"
    
    if transpiled:
        content.append(transpiled)

output = output.replace("CONTENT", "\n    ".join(content))

with open("x.c", "w") as f:
    f.write(output)

print("Transpiler END")
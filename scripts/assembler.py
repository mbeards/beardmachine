


ops = {'LOAD': 1, 'LIT': 12, 'CPS': 5, 'HALT': 15, 'READ': 11, 'J': 8, 'JLE': 9, 'NOR': 7, 'PRINT': 10, 'CP': 3, 'NOP': 0, 'CSP': 4, 'STORE': 2, 'INC': 6}


program = [["LIT", 3, 0], [0b111], ["CPS", 3, 1], ["LIT", 3, 0], [254], ["CP", 1, 2], ["INC", 1, 0], ["JLE", 3, 1], ["HALT"]]

for op in program:
  if len(op) == 1:
    op.append(0)
  if len(op) == 2:
    op.append(0)


s = []
lit = False
for op in program:
  if lit:
    lit = False
    s.append(op[0])
  elif(op[0] == ops["HALT"]):
    s.append(ops[op[0]])
  else:
    if(op[0] == "LIT"):
        lit = True
    s.append((ops[op[0]] * 16) + (op[1]*4) + op[2])

print "{", ",".join(map(str, s)), "}"

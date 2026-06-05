input_str = "Let's take Python contest"

n = len(input_str)

words = input_str.split()
    
output_str = ""

for i in range(len(words)):
  word = words[i]
  revd = word[::-1]
  if (i != len(words) - 1):
    output_str += revd + " "
  else:
    output_str += revd
print(output_str)

# for word in words:
#   revd = word[::-1]
#   output_str += revd + " "
  
# print(output_str)
# OpenAI_API.py

from openai import OpenAI
import openai

# ------------------------------------------------------------------------------
# Enter your OpenAI API key here

apiKey = ""

# ------------------------------------------------------------------------------

# client = OpenAI(api_key=apiKey)
openai.api_key = apiKey
import sys

def generate_mips_from_ir(api_key, ir_code):
    OpenAI.api_key = api_key

    messages = [
        {"role": "user", "content": f"Convert the following IR code to Standard MIPS Assembly to be run in QTSpim. Don't use subi. Do not use the array() method:\n{ir_code}"}
    ]

    # Use 'gpt-3.5-turbo' as the model name
    model_name = "gpt-3.5-turbo"

    response = openai.chat.completions.create(
        model=model_name,
        messages=messages,
        temperature=1.0,
        max_tokens=2000,
        n=1
    )

    mips_code = response.choices[0].message.content.strip()
    # one_line_code = mips_code.replace('\n', ' ')
    print(mips_code)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python your_openai_script.py <API_KEY> <IR_CODE>")
        sys.exit(1)

    api_key = sys.argv[1]
    ir_code = sys.argv[2]
    

    generate_mips_from_ir(api_key, ir_code)


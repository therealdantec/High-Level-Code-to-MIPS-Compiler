# OpenAI_API.py

from openai import OpenAI
import openai

apiKey = "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"
# this is christian's key
# client = OpenAI(api_key=apiKey)
openai.api_key = apiKey
import sys

def generate_mips_from_ir(api_key, ir_code):
    OpenAI.api_key = api_key

    messages = [
        {"role": "user", "content": f"Convert the following code to Standard MIPS Assembly to be run in QTSpim. Don't use subi or addiu. prints have a newline. the default case in the switch statements aren't labeled, and come after the case code blocks. Give me only the MIPS code, do not say anything else:\n{ir_code}"}
    ]

    # Use 'gpt-4' as the model name
    model_name = "gpt-4"

    response = openai.chat.completions.create(
        model=model_name,
        messages=messages,
        temperature=1.0,
        max_tokens=2000,
        n=1
    )

    mips_code = response.choices[0].message.content.strip()
    
    response = openai.chat.completions.create(
        model=model_name,
        messages=[
        {"role": "user", "content": f"Check the following Standard MIPS Assembly to be run in QTSpim for errors and fix them. Don't use subi. Give me only the MIPS code, do not say anything else.\n{mips_code}"}
        ],
        temperature=1.0,
        max_tokens=2000,
        n=1
    )
    mips_code = response.choices[0].message.content.strip()
    print(mips_code)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python your_openai_script.py <API_KEY> <IR_CODE>")
        sys.exit(1)

    api_key = sys.argv[1]
    ir_code = sys.argv[2]
    

    generate_mips_from_ir(api_key, ir_code)


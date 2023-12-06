# your_openai_script.py

from openai import OpenAI
import openai

apiKey = "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"

# client = OpenAI(api_key=apiKey)
openai.api_key = apiKey
import sys

def generate_mips_from_ir(api_key, ir_code):
    OpenAI.api_key = api_key

    messages = [
        {"role": "user", "content": f"Convert the following IR code to MIPS Assembly:\n{ir_code}"}
    ]

    # Use 'gpt-3.5-turbo' as the model name
    model_name = "gpt-3.5-turbo"

    response = openai.chat.completions.create(
        model=model_name,
        messages=messages,
        temperature=1.0,
        max_tokens=200,
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

    print("I AM ALIVE")
    print(ir_code)

    generate_mips_from_ir(api_key, ir_code)


#define TEXT_OUTPUT_ADDRESS 0x0000000004000000

typedef struct _TEXT_OUTPUT TEXT_OUTPUT;

struct _TEXT_OUTPUT {
	unsigned long long unused1;
	unsigned long long (*output_string)(TEXT_OUTPUT*, unsigned short*);
};

void kputs(unsigned short* buffer) {
	TEXT_OUTPUT* text_output = (TEXT_OUTPUT*)TEXT_OUTPUT_ADDRESS;
	text_output->output_string(text_output, buffer);
}

void _start(void) {
	kputs(L"Hello, kernel!\r\n");
}

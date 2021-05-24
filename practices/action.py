class Controller(object):
    def execute(self, action):
        action.run()
    
class CreateHelloPy(object):
    def run(self):
        with open("hello.py", "w") as f:
            f.write('print("Hello World")')
    
class CreateHelloC(object):
    def run(self):
        with open("hello.c", "w") as f:
            f.write('#include <stdio.h>\n\nint main(void)\n{\n\tprintf("Hello, World\\n");\n}')
            

if __name__ == "__main__":
    c = Controller()
    py = CreateHelloPy()
    c.execute(py)
    hel_c = CreateHelloC()
    c.execute(hel_c)
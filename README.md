# Custom implementation of C's Printf function.
## Project Overview
This project is a custom implementation of the C standard library’s printf function. The implementation is designed as a state machine and aims to replicate most of the functionalities provided by the standard printf function.
Features
•	State Machine Design: Utilizes a state machine to handle various formatting states.
•	Format Specifiers: Supports a wide range of format specifiers including %d, %s, %c, %f, and more.
•	Modifiers: Implements width, precision, and length modifiers.
•	Error Handling: Includes basic error handling for unsupported format specifiers and invalid inputs.


## Usage
To use this custom printf function, include the header file and call the function as you would with the standard printf.
```c
#include "_printf.h"
int main()
{
    _printf("Hello, %s! You have %d new messages.\n", "User", 5);
    return 0;
}
```


## Installation
1.	Clone the repository:
    ```git
       git clone https://github.com/odarym/printf.git
    ```
2.	Navigate to the project directory:
3.	Compile the source code:
   ```make
        make
   ```

## Testing
The project includes a set of test cases to verify the functionality of the custom printf implementation. Run the tests using:
make test


## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your changes.

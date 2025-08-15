# 🐚 Minishell

Welcome to **Minishell** - a lightweight, Unix-like shell implementation in C! This project is a fun dive into the world of command-line interfaces and operating system concepts. 

## 🚀 Features

- **Command Parsing & Execution**: Run your commands seamlessly!
- **Built-in Commands**: Includes essential commands like `cd` and `exit`.
- **Input/Output Redirection**: Redirect output and input with `>` and `<`.
- **Piping**: Chain commands with `|` for streamlined workflows.
- **Signal Handling**: Responds gracefully to signals like Ctrl+C.
- **Environment Variables**: Manage your environment like a pro!

## 🛠️ Getting Started

### Prerequisites

To get started, you’ll need:

- A Unix-like environment (Linux, macOS, etc.)
- GCC (GNU Compiler Collection)

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/IlyVoid/minishell.git
   cd minishell

Compile the project:
make

Run the shell:
./minishell

🎉 Usage

Once you have it running, try out some commands:

Change directory:
cd <directory>

List files:
ls -l

Output redirection:
echo "Hello, World!" > hello.txt

Piping commands:
ls -l | grep "txt"

Exit the shell:
    exit

📂 Project Structure

makefile

minishell/
├── src/             # Source files
├── include/         # Header files
├── Makefile         # Build instructions
├── README.md        # Project documentation
└── ...

📫 Contact

Have questions or feedback? Feel free to reach out:

    Author: IlyVoid

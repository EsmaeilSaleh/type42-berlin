# Type42 Berlin

🇩🇪 [Deutsche Version](README.de.md)

**Type42 Berlin** is a terminal-based application designed to help students and C language enthusiasts practice writing `libft` functions. It's especially useful for 42 school students who want to improve their muscle memory and clean C coding skills.

---

## 🎯 Features

- Two practice modes:
  - **Copy Mode**: Code is displayed and you must retype it exactly
  - **Recall Mode**: Only the function name and description are shown — you must type the function from memory
- Checks your code with **Norminette** and shows formatted error output
- Displays **typing accuracy** and **Norminette compliance** after each session
- Functions categorized by type (string, memory, list, I/O, etc.)
- Ideal for practicing **Libft**, preparing for **get_next_line**, **ft_printf**, and technical interviews

---

## 🧠 Goals

- Strengthen muscle memory for C standard functions
- Gain confidence in clean coding and syntax
- Prepare for coding challenges and C-based projects
- Become familiar with Norminette-style formatting and error fixing

---

## 🛠 Usage

```bash
git clone git@github.com:EsmaeilSaleh/type42-berlin.git
cd type42-berlin
make
./type42
```

> 📦 **Note:** To enable Norminette checks, you must have the official `norminette` tool installed.
> Install it via:
>
> ```bash
> pip install norminette
> ```
>
> Or refer to the [42 Norminette GitHub page](https://github.com/42School/norminette) for alternative setup instructions.

> The app runs in the terminal and uses a simple keylogger to compare your typed code with the expected version.

---

## 🔍 Project Structure

- `src/` — Main logic and function definitions
- `includes/` — Header files and `LibFunc` structure
- `score_log.txt` — Training logs and scores
- `Makefile` — For easy build and execution

---

## ✨ Contribution

Got suggestions, bugs, or want to add new functions? Open an issue or submit a PR!

---

## 🧾 License

MIT License © 2025 [Esmaeil Saleh](https://www.linkedin.com/in/esmaeil-saleh/)

# C Mastery Plan — The Gym Body Analogy

> Mastery is an illusion. The goal is to feel confident enough to improve every single day.

---

## The Core Formula

```
DIET (Anki + Docs + Understanding WHY)  =  60–70%
TRAINING (Coding sessions)              =  30–40%
```

Coding hard without reviewing = training twice a day without eating.
Both are required. Every single day. No exceptions.

---

## 01 — The Muscle Groups (C Domains)

| 💪 Body | ⌨️ C Equivalent | ★ Priority |
|---|---|---|
| 🍑 Glutes *(favorite)* | **Processes & System Calls** — fork / exec / wait / pipes / signals | ★★★★★ Anchor |
| 🏋️ Chest | **Pointers & Memory** — arith, malloc/free, void\* | ★★★★★ Power |
| 🦵 Legs | **Data Structures** — arrays, structs, linked lists | ★★★★☆ Foundation |
| 🔙 Back | **Functions & Scope** — how everything links | ★★★★☆ Pull |
| 🤸 Shoulders | **String & I/O** — string.h, printf, file I/O | ★★★☆☆ Shape |
| 🧘 Core | **Headers, Makefile, Compilation** — invisible but critical | ★★★★☆ Stability |
| 💪 Arms | **Bitwise & Error Handling** — edge cases, norms | ★★★☆☆ Definition |
| 🦶 Calves | **Debugging Tools** — valgrind, gdb, fsanitize | ★★☆☆☆ Finishing |

---

## 02 — Glutes Breakdown (Your Anchor Group)

Three sub-muscles. Train each one intentionally.

| 🍑 Glute | C Sub-concept | Why It Matters |
|---|---|---|
| **Gluteus Maximus** *(biggest power)* | `fork / exec / wait` | The heavy compound lift. Controls process creation and lifecycle. |
| **Gluteus Medius** *(stability/shape)* | Pipes & File Descriptors | Connects everything. Without this, data can't flow between processes. |
| **Gluteus Minimus** *(definition)* | Signals & Environment | Subtle but visible. `env`, `kill`, `signal()` are the finishing details. |

When motivation drops or you feel lost — **default to this group.**
It's your strongest leverage point. Always come back here.

---

## 03 — Diet (The 60–70% That Decides Everything)

| 🥗 Nutrition | C Equivalent | Your Practice |
|---|---|---|
| **Total Calories** *(raw fuel)* | Reading docs — man pages, Beej's Guide, standards | Beej sessions |
| **Protein** *(repair & growth)* | Anki repetition — consolidate what you trained | Daily deck reviews |
| **Carbs** *(session energy)* | Reading others' clean code before writing | 42 peer code review |
| **Fats** *(long-term hormones)* | Understanding WHY — not just what works | Defense prep — explain decisions out loud |
| **Water** *(everything depends on it)* | Sleep & recovery — brain consolidates memory here | Non-negotiable. Protect it. |
| **Meal timing** *(pre/post workout)* | Review concepts before and after each session | Anki before coding. Anki after. |

> **The hard truth:** Someone who codes all day but skips Anki and never reads docs
> = someone who trains twice a day but eats nothing.
> Exhausted. Feels productive. Nothing is actually building.

---

## 04 — The Weekly Split

You don't train chest + shoulders + arms on the same day.
Same rule applies here.

| Day | Gym | Main C Focus *(Heavy)* | Complementary *(15 min)* |
|---|---|---|---|
| **Mon** | 🍑 Glutes | Processes: fork / exec / wait | Signals & env vars |
| **Tue** | 🏋️ Chest | Pointers: arith / malloc / void\* | Error handling & norms |
| **Wed** | 🔙 Back | Data Structures: structs / linked lists | Makefile / headers |
| **Thu** | 🦵 Legs | Pipes & File Descriptors | Bitwise operations |
| **Fri** | 🤸 Shoulders | String ops / I/O / file handling | Debugging: valgrind |
| **Sat** | 📖 Full review | Project work — integrate the week | Anki all decks |
| **Sun** | 🛌 Recovery | Read clean code — no writing | Sleep. Protect this. |

> **The complementary rule:** The light topic never taxes the same mental muscle as the heavy one.
> Makefiles don't interfere with pointer arithmetic.
> You keep compounding on small things while the main group does the heavy work.

---

## 05 — Progressive Overload (How You Actually Grow)

| 🏋️ Gym Principle | ⌨️ C Equivalent | In Practice |
|---|---|---|
| Add weight each week | Add a layer of indirection: `*ptr → **ptr → fn pointer` | One abstraction per week |
| More sets | More edge cases to handle | Null checks, overflow, limits |
| Compound lifts first | Hardest concept before cleanup | Logic first. Norm after. |
| Isolation after compound | Formatting, error msgs after logic works | Norminette is your isolation work |
| Deload week | Read & review — no new projects | Anki only, read Beej again |

---

## 06 — Deep C (Beyond Any Exam)

The domains worth going deep on — no deadlines, just depth.

### Pointers & Memory (Chest)
- Pointer arithmetic and decay
- `malloc` / `free` full lifecycle — when it fails, what leaks, why
- `void *` and type-agnostic design
- Function pointers — callbacks, dispatch tables
- Stack vs heap — when to use which and why

### Processes (Glutes — your anchor)
- `fork()` — what actually gets copied
- `exec()` family — why fork before exec
- `wait()` / `waitpid()` — zombie processes and why they happen
- File descriptors — inheritance across fork
- `dup2()` — redirecting stdin/stdout/stderr

### Pipes & IPC (Glute Medius)
- Anonymous pipes — `pipe()`, fd[0]/fd[1], read/write cycle
- Why you must close unused ends
- Chaining commands like a shell does
- Named pipes (FIFOs) — when and why

### Threads (coming soon — Philosophers)
- `pthread_create` / `pthread_join`
- Mutexes — what a race condition actually looks like
- Deadlocks — how to think about them, how to avoid them
- The dining philosophers problem is literally this

### Data Structures (Legs)
- Linked list — singly, doubly, circular
- Stack and queue from scratch
- Hash map basics
- When to use which and the cost of each

### Strings & I/O (Shoulders)
- `strlen`, `strcpy`, `strcat` — and why they're dangerous
- `write()` vs `printf()` — buffered vs unbuffered
- Reading files with `read()` and `open()`

---

## 07 — Weekly Check-In

Run this every Sunday before recovery day.

- [ ] Did I hit my anchor day (Processes) this week?
- [ ] Did I review Anki every day — diet before training?
- [ ] Did I understand WHY in every session, not just WHAT?
- [ ] Did I do the complementary 15 min on each main day?
- [ ] Did I rest and protect my sleep?

### Signs you're undertrained
- You write code but can't explain what `fork()` actually does
- You pass the test but can't defend the decision
- You finish a project but feel no ownership over it

### Signs you're underfed
- Your Anki streak is broken
- You stopped reading Beej
- You only look at code when writing it — never absorbing
- You forget things you "already learned"

### The plateau fix
Almost always diet, not more training.
Do a deload week — no new code, just review. Read Beej. Do Anki. Sleep. Progress resumes.

---

## 08 — Current Focus (Rank 03)

**Philosophers** → Threads, mutexes, deadlocks — this is Glute Medius territory.
Start by feeling the race condition before you fix it. Don't just mutex everything blindly.

**Minishell** → Pipes, processes, file descriptors all at once.
This is a full Glutes day. Every single session.

---

*Update this file as you go deeper. It's a living document, not a syllabus.*

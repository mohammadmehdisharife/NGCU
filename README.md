# NGCU - Next Generation Coreutils

**NGCU (Next Generation Coreutils)** is a collection of lightweight, GNU-style command-line utilities written in **C**, designed to extend and modernize the traditional GNU coreutils toolkit.  
Each utility follows UNIX philosophy — *do one thing and do it well.*

---

## 📦 Repository

**GitHub:** [https://github.com/mohammadmehdisharife/NGCU](https://github.com/mohammadmehdisharife/NGCU)

---

## ⚙️ Included Utilities

| Command | Description |
|----------|--------------|
| **pure** | Reads text from `stdin` and removes ANSI color codes or other display artifacts (future versions may support emoji stripping). |
| **clip** | Saves text from either command-line arguments or standard input into a persistent clipboard file (`/tmp/.clip`). |
| **clipcat** | Prints the contents of the clipboard file (`/tmp/.clip`) to standard output. |
| **safe_rm** | A safe replacement for `rm`; instead of deleting files, it moves them to `~/.trash`. Includes a `--empty` option to permanently clear the trash. |

---

## 💡 Usage Examples

### `pure`
```bash
ls --color=always | pure
```
Removes ANSI color codes from `ls` output.

---

### `clip` and `clipcat`
```bash
echo "Hello NGCU!" | clip
clipcat
# Output: Hello NGCU!
```

You can also provide arguments:
```bash
clip Hello from NGCU
clipcat
# Output: Hello from NGCU
```

---

### `safe_rm`
```bash
safe_rm old.txt
# Moves old.txt to ~/.trash

safe_rm --empty
# Completely clears the trash directory

safe_rm --help
# Shows usage instructions
```

---

## 🧩 Project Structure

```
NGCU/
├── src/
│   ├── pure.c
│   ├── clip.c
│   ├── clipcat.c
│   ├── safe_rm.c
├── Makefile
└── README.md
```

---

## 🧠 Philosophy

NGCU follows these core design principles:

1. **Simplicity:** Each utility performs one clear function.  
2. **Compatibility:** Follows GNU-style flags and conventions.  
3. **Transparency:** No background daemons or binary data formats.  
4. **Extensibility:** New tools can easily be added under `src/`.

---

## 🧾 License

This project is released under the **GNU General Public License v3 (GPLv3)**, consistent with GNU coreutils.

---

## ✨ Roadmap

- [ ] Add emoji removal to `pure`
- [ ] Add `restore_rm` command to recover files from Trash
- [ ] Add `clip --clear` option
- [ ] Write man pages for each utility

---

## 👨‍💻 Author

**Mohammad Mehdi Sharife 🇮🇷**  
<https://github.com/mohammadmehdisharife>

---

*“Small tools, solid principles — NGCU: The next generation of core utilities.”*


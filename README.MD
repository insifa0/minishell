# 🐚 Minishell: A Simplified Unix Shell

Bu proje, günlük hayatta kullanılan **Bash/Zsh** gibi shell yapılarının temel mantığını anlamak için sıfırdan **C dili** ile geliştirilmiş bir öğrenme projesidir. Unix süreç modelini, sistem çağrılarını ve süreçler arası iletişimi (IPC) derinlemesine pratik eder.

## 🚀 Özellikler

| Özellik | Açıklama |
| --- | --- |
| **REPL Döngüsü** | Kullanıcıdan komut alıp, işleyip, sonuç döndüren döngü yapısı. |
| **Process Model** | `fork()`, `execvp()` ve `waitpid()` ile harici programları çalıştırma. |
| **Pipeline** | `pipe()` ve `dup2()` kullanarak komutları birbirine bağlama (`ls | grep .c`). |
| **Built-in Komutlar** | `cd`, `exit`, `export`, `env` gibi kabuğa gömülü fonksiyonlar. |
| **Signal Handling** | `Ctrl+C` sinyalini yakalayarak shell'in kapanmasını önleme. |
| **Dinamik Prompt** | Mevcut çalışma dizinini (CWD) gösteren renkli ve interaktif arayüz. |

## 🏗️ Mimari Yapı

Proje, veriyi girdi olarak alıp işleyene kadar şu aşamalardan geçer:

1. **Lexer (Tokenizer):** Girdiyi anlamlı kelime parçalarına ayırır.
2. **Parser/Handler:** Komutun built-in mi, pipe mı yoksa standart bir komut mu olduğunu belirler.
3. **Executor:** Uygun sistem çağrılarını tetikleyerek işlemi gerçekleştirir.

## 🛠️ Kurulum ve Çalıştırma

Projenin derlenmesi için `gcc` ve `libreadline` kütüphanesi gereklidir.

1. **Projeyi derleyin:**
```bash
make

```


2. **Shell'i başlatın:**
```bash
./minishell

```



## 📚 Kullanılan Sistem Çağrıları

* `fork`, `execvp`, `waitpid`
* `pipe`, `dup2`
* `chdir`, `getcwd`
* `signal`, `sigaction`

## 🗺️ Gelecek Özellikler (Roadmap)

* [ ] **Redirection:** `>`, `>>`, `<` operatörleri ile dosya yönlendirme.
* [ ] **Backgrounding:** `&` operatörü ile süreçleri arka planda çalıştırma.
* [ ] **History:** Geçmiş komutlara erişim desteği.

---
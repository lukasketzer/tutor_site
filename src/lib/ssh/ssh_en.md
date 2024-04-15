In this guide you will learn how to set up SSH on you mashine to access the **Rechnerhalle**.

# Overview

- [Overview](#overview)
- [RBG-Account / ITO-Account](#rbg-account--ito-account)
- [Install OpenSSH](#install-openssh)
- [SSH](#ssh)
- [SSH without a password](#ssh-without-a-password)

# RBG-Account / ITO-Account

For all of this to work you need a **RBG-Account**. There is an official guide on the [ITO-Wiki](https://www.cit.tum.de/ito/fuer-studierende/fuer-neue/). I advise you to use the official wiki if you have more questions regarding your RBG-Account.

You should have gotten an email with a link to activate your account. This email also contains instructions which you can follow to help you with the activation.

# Install OpenSSH

Here, you will learn how setup `ssh` on your system to access the **Rechnerhalle**

## Windows (WSL)

I would advise you to use WSL on windows if you want to use `ssh`.
[Here](https://learn.microsoft.com/en-us/windows/wsl/install) is the link to the official documentation.

```sh
# Open windows powershell or Windows-CMD
> wsl --install
```

From now on, you can follow the [**Linux**](#linux) guide to install `ssh`.

## macOS

In the newest MacOs-versions, `ssh` is already installed by default.
Check by executing the following command.

```sh
> ssh
```

If `ssh` is installed, you should get a **usage**-message.

## Linux

To use the `ssh` command on Linux, you need to install `openssh-client`. Most Linux-distributions already have a `ssh-client` installed so the installation step can be skiped

**Ubuntu** (and WSL)

```sh
> sudo apt update  # updates the mirrors 
> sudo apt openssh-client  # install the ssh-client
```

**Arch-based**

```sh
> sudo pacman -Syu  # updates the mirrors 
> sudo pacman -S openssh-client  # install the ssh-client
```

### Check if SSH was installed succesfully

```sh
> ssh
```

If everything was done correctly you should get a **usage**-message looking something like this:

```sh
usage: ssh [-46AaCfGgKkMNnqsTtVvXxYy] [-B bind_interface] [-b bind_address]
           [-c cipher_spec] [-D [bind_address:]port] [-E log_file]
           [-e escape_char] [-F configfile] [-I pkcs11] [-i identity_file]
           [-J destination] [-L address] [-l login_name] [-m mac_spec]
           [-O ctl_cmd] [-o option] [-P tag] [-p port] [-R address]
           [-S ctl_path] [-W host:port] [-w local_tun[:remote_tun]]
           destination [command [argument ...]]
       ssh [-Q query_option]

```

# SSH

`ssh` is basic command to connect on the **Rechnerhalle**. This is the same command wether you are using a Linux-distribution, MacOS or WSL (Windows).

```sh
> ssh <ito-username>@lxhalle.in.tum.de
# Example:
> ssh smith@lxhalle.in.tum.de
```

# SSH without a password

### Why should you set up an SSH-Key?

As you may already have noticed, you must alway enter you RBG-password when connecting to the **Rechnerhalle** via the `ssh` command. This can be annoying if you are planing on using the Rechnerhalle on a regular basis.

Luckily there is a solution. You can create an **SSH-Key-Pair** and send you **public-key** to the **Rechnerhalle**.

If you want to read more about how this works [here](https://www.ssh.com/academy/ssh/public-key-authentication) is a link.



### Creating an SSH-Key-Pair
### !!! All of the following commands should be executed on your local machine not on the Rechnerhalle !!!
```sh
> ssh-keygen -t ed25519
```

After executing the command you will get a prompt something like this

```sh
Generating public/private ed25519 key pair.
Enter file in which to save the key (path/to/home/.ssh/id_ed25519):  # press <Enter>
```

Press `<Enter>` to continue with the default name or enter a name for you file

For the next step, you will be prompted to **assign a password** to the **SSH-Key**

```sh
# You don't want to enter a password here. (Otherwise you will have to enter you password everytime you use ssh)
Enter passphrase (empty for no passphrase):  # press <Enter>
Enter same passphrase again:                 # press <Enter>
```

You want to press `<Enter>` and leave the password-field empty. If you choose to enter a password, you will need to enter the password everytime you use the key pair.

If you followed those steps correctly you will now find two new files in the directoy: `~/.ssh`.

```sh
> ls -l ~/.ssh
-rw------- 1 user user  411 13. Jan 13:05 id_ed25519
-rw-r--r-- 1 user user  102 13. Jan 13:05 id_ed25519.pub
```

`id_ed25519` is your private-key. You should keep it secret. `id_ed25519.pub` is your **public-key**. In the next step you will send this **public-key** to the **Rechnerhalle** to authenticate yourself.

### Send your public-key to the Rechnerhalle

In this step you will be sending your public key to the **Rechnerhalle**.

```sh
> ssh-copy-id -i ~/.ssh/id_ed25519.pub <ito-username>@lxhalle.in.tum.de 
# Example: ssh-copy-id -i ~/.ssh/id_ed25519.pub smith@lxhalle.in.tum.de
```

This command copys the public key, specified with **`-i ~/.ssh/id_ed25519.pub`** to the **Rechnerhalle**

### Accessing the Rechnerhalle

From now on you can use the following commad to connect to the Rechnerhalle without entering a password.

```sh
> ssh <ito-username>@lxhalle.in.tum.de
# Example: ssh smith@lxhalle.in.tum.de
```

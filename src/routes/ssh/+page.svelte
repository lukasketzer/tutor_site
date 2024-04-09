<svelte:head>
    <title>SSH Guide | Lukas Ketzer</title>
    <link
        rel="stylesheet"
        href="https://cdnjs.cloudflare.com/ajax/libs/github-markdown-css/5.5.1/github-markdown-dark.min.css"
        integrity="sha512-MmL2FuLmm/UH05Ah4JiJwA+G7OCceZDpzGHWqsju4Espzq+9nwQJdQVMNZPd1FNK2H3qDYXdET7HNG7Qm93FEg=="
        crossorigin="anonymous"
        referrerpolicy="no-referrer"
    />
</svelte:head>

<div class="container markdown-body">
    <h1 id="install-ssh"><strong>Install SSH</strong></h1>
    <p>
        In this guide you will learn how setup <code>ssh</code> on your system
        to access the <strong>Rechernerhale</strong>
    </p>
    <h2 id="windows-wsl"><strong>Windows (WSL)</strong></h2>
    <p>
        I would advise you to use WSL on windows if you want to use <code
            >ssh</code
        >.
    </p>
    <h2 id="macos"><strong>MacOs</strong></h2>
    <h2 id="linux"><strong>Linux</strong></h2>
    <p>
        First of all you need to install <code>openssh-client</code> to use the
        <code>ssh</code>
        command on linux. Most Linux-distributions already have an
        <code>ssh-client</code> installed so the Installatin-step can be skiped
    </p>
    <p><strong>Ubuntu</strong></p>
    <pre><code class="language-sh"
            >&gt; sudo apt update  # updates the mirrors 
    &gt; sudo apt openssh-client  # install the ssh-client
    </code></pre>
    <p><strong>Arch-based</strong></p>
    <pre><code class="language-sh"
            >&gt; sudo pacman -Syu  # updates the mirrors 
    &gt; sudo pacman -S openssh-client  # install the ssh-client
    </code></pre>
    <h1 id="accessing-the-rechnerhalle">
        <strong>Accessing the Rechnerhalle</strong>
    </h1>
    <p>
        The basic command to connect on the <strong>Rechnerhalle</strong>. This
        is the same command wether you are using a Linux-distribution, MacOS or
        WSL (Windows).
    </p>
    <pre><code class="language-sh"
            >&gt; ssh &lt;rbg-username&gt;@lxhalle.in.tum.de
    # Example:
    &gt; ssh ketz@lxhalle.in.tum.de
    </code></pre>
    <h1 id="setting-up-an-ssh-key-pair">
        <strong>Setting up an SSH-Key-Pair</strong>
    </h1>
    <h4 id="why-should-you-set-up-an-ssh-key">
        <strong>Why should you set up an SSH-Key?</strong>
    </h4>
    <p>
        As you may already have noticed, you must alway enter you RBG-password
        when connecting to the <strong>Rechnerhalle</strong>. This can be
        annoying if you are planing to use the Rechnerhalle on a regular basis.
    </p>
    <p>
        Luckily there is a solution. You can create an <strong
            >SSH-Key-Pair</strong
        >
        and send you <strong>public-key</strong> to the
        <strong>Rechnerhalle</strong>. From now on, you can connect to the
        Rechnerhalle without entering a password all the time.
    </p>
    <p>
        If you want to read more about how this works <a
            href="https://www.ssh.com/academy/ssh/public-key-authentication"
            >here</a
        > is a link.
    </p>
    <h3 id="creating-an-ssh-key-pair">Creating an SSH-Key-Pair</h3>
    <pre><code class="language-sh"
            >&gt; ssh-keygen -t ed25519
    </code></pre>
    <p>After executing the command you will get a prompt something like this</p>
    <pre><code class="language-sh"
            >Generating public/private ed25519 key pair.
    Enter file in which to save the key (&lt;path_to_home&gt;/.ssh/id_ed25519):  # press &lt;Enter&gt;
    </code></pre>
    <p>
        Press <code>&lt;Enter&gt;</code> to continue with the default name or enter
        a name for you file
    </p>
    <p>
        For the next step, you will be prompted to <strong
            >assign a password</strong
        >
        to the <strong>SSH-Key</strong>
    </p>
    <pre><code class="language-sh"
            >Enter passphrase (empty for no passphrase):  # press &lt;Enter&gt; or choose a password
    Enter same passphrase again:                 # press &lt;Enter&gt; or repeat you password
    </code></pre>
    <p>
        You want to press <code>&lt;Enter&gt;</code> and leave the password-field
        empty. If you choose to enter a password, you will need to enter the password
        everytime you use the Key-Pair.
    </p>
    <p>
        If you followed those steps, correctly you will now find two new files
        in the directoy: <code>~/.ssh</code>.
    </p>
    <pre><code class="language-sh"
            >&gt; ls -l ~/.ssh
    -rw------- 1 user user  411 13. Jan 13:05 id_ed25519
    -rw-r--r-- 1 user user  102 13. Jan 13:05 id_ed25519.pub
    </code></pre>
    <p>
        <code>id_ed25519</code> is your private-key. You should keep it secret.
        <code>id_ed25519.pub</code>
        is your <strong>public-key</strong>. In the next step you will send this
        <strong>public-key</strong>
        to the <strong>Rechnerhalle</strong> to authenticate yourself.
    </p>
    <h3 id="send-your-public-key-to-the-rechnerhalle">
        Send your public-key to the Rechnerhalle
    </h3>
    <p>
        In this step you will be sending your public-key to the <strong
            >Rechnerhalle</strong
        >.
    </p>
    <pre><code class="language-sh"
            >&gt; ssh-copy-id -i ~/.ssh/id_ed25519.pub &lt;rbg-username&gt;@lxhalle.in.tum.de 
    # Example: ssh-copy-id -i ~/.ssh/id_ed25519.pub ketz@lxhalle.in.tum.de
    </code></pre>
    <p>
        This command copys the public-key, specified with <strong
            ><code>-i ~/.ssh/id_ed25519.pub</code></strong
        >
        to the <strong>Rechnerhalle</strong>
    </p>
    <h3 id="accessing-the-rechnerhalle-1">Accessing the Rechnerhalle</h3>
    <p>
        From now on you can use the following commad to connect to the
        Rechnerhalle without entering a password.
    </p>
    <pre><code class="language-sh"
            >&gt; ssh &lt;rbg-username&gt;@lxhalle.in.tum.de
    </code></pre>
</div>

<style>
    .markdown-body {
        box-sizing: border-box;
        min-width: 200px;
        max-width: 980px;
        margin: 0 auto;
        padding: 45px;
        background-color: #14161a;
    }

    @media (max-width: 767px) {
        .markdown-body {
            padding: 15px;
        }
    }
</style>

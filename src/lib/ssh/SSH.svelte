<script>
    import powershell from "$lib/ssh/powershell.png";
</script>

<div class="container markdown-body">
    <p>
        In diesem Guide werdet ihr lernen, wie ihr SSH auf euer Maschine
        einrichtet, so dass ihr euch auf die <strong>Rechnerhalle</strong>
        verbinden könnt. Dieser Guide ist eine Alternative zu dem
        ausführlicheren
        <a
            href="https://wiki.ito.cit.tum.de/bin/view/Informatik/Helpdesk/WebHome"
            >ITO-Wiki</a
        >.
    </p>
    <h1 id="übersicht">Übersicht</h1>
    <ul>
        <li><a href="#%C3%BCbersicht">Übersicht</a></li>
        <li>
            <a href="#rbg-account--ito-account">RBG-Account / ITO-Account</a>
        </li>
        <li><a href="#ssh-installieren">SSH installieren</a></li>
        <li><a href="#ssh">SSH</a></li>
        <li><a href="#ssh-ohne-passwort">SSH ohne Passwort</a></li>
        <!-- <li><a href="#ssh-ohne-passwort">SSH Config</a></li> -->
        <li><a href="https://code.visualstudio.com/docs/remote/ssh">SSH in VSCode</a></li>
    </ul>
    <h1 id="rbg-account--ito-account">RBG-Account / ITO-Account</h1>
    <p>
        Damit du die Rechnerhalle verwenden kannst, brauchst du einen <strong
            >RBG- / ITO-Account</strong
        >. Zu Beginn des ersten Semesters habt solltest du eine Email bekommen,
        in dem ein Link ist, mit dem du einen
        <strong>RBG- / ITO-Account</strong>
        erstellen kann. Bei Fragen und Unklarheiten kann man im offizielles
        <a href="https://www.cit.tum.de/ito/fuer-studierende/fuer-neue/"
            >ITO-Wiki</a
        > nachschlagen.
    </p>
    <h1 id="ssh-installieren">SSH installieren</h1>
    <p>
        In diesem Abschnitt wird erklärt, wie man <code>ssh</code> installiert.
    </p>
    <h2 id="windows-wsl">Windows (WSL)</h2>
    <p>
        Aus Erfahrung würde ich allen Windows-Nutzern empfehlen <code>ssh</code>
        über WSL (Windows Subsystem for Linux) zu nutzen. Man kann
        <code>ssh</code> auch über Windows nativ benutzen, die Einrichtung ist meiner
        Meinung nacher aber komplizierter und in der Vergangheit habe ich immer wieder
        Probleme bei Windows gesehen.
    </p>
    <h3 id="wsl-installieren">WSL installieren</h3>
    <p>
        <a href="https://learn.microsoft.com/en-us/windows/wsl/install"
            >Offizielle Microsoft Dokumentation</a
        >.
    </p>
    <p>
        Zuerst muss WSL für Windows aktiviert werden. Dafür musst du die <strong
            >Windows PowerShell</strong
        >
        oder <strong>Windows-CMD</strong> öffnen und folgenden Befehl ausführen.
    </p>
    <p><img src={powershell} alt="Powershell öffnen" /></p>
    <pre><code class="language-sh"
            ># In Windows Powershell 
&gt; wsl --install -d ubuntu</code></pre>
    <p>
        Sobald sich eine neue Shell mit Linux öffnet, kannst du weiter dem <a
            href="#linux"><strong>Linux</strong></a
        >
        Guide folgen um <code>ssh</code> zu installieren.
    </p>
    <h2 id="macos">macOS</h2>
    <p>
        Auf den neueren <strong>macOS</strong>-Versionen sollte <code>ssh</code>
        schon installiert sein. Um zu prüfen, ob <code>ssh</code> richtig
        funktioniert, musst du den <strong>Terminal</strong> öffnen und den folgenden
        Command ausführen.
    </p>
    <pre><code class="language-sh"
            >&gt; ssh</code></pre>
    <p>
        Wenn <code>ssh</code> installiert ist, solltest du eine
        <a href="#pr%C3%BCfen-ob-ssh-installiet-ist"
            ><strong>usage</strong>-Message</a
        > bekommen wie sie weiter unten zu sehen ist.
    </p>
    <h2 id="linux">Linux</h2>
    <p>
        <code>ssh</code> ist auf den meißten Linux-Distros (auf WSL auch) schon
        standartmäßig installiert. Sollte das nicht so sein kannst du den
        folgenden Schritten folgen um <code>openssh-client</code> für dein Distro
        zu installieren.
    </p>
    <h3 id="ubuntu-and-wsl">Ubuntu (and WSL)</h3>
    <pre><code class="language-sh"
            >&gt; sudo apt update  # updates the mirrors 
&gt; sudo apt openssh-client  # install the ssh-client</code></pre>
    <h3 id="arch-based-manjaro-endeavour-">
        Arch-based (Manjaro, Endeavour, ...)
    </h3>
    <pre><code class="language-sh"
            >&gt; sudo pacman -Syu  # updates the mirrors 
&gt; sudo pacman -S openssh-client  # install the ssh-client</code></pre>
    <h3 id="prüfen-ob-ssh-installiet-ist">Prüfen ob SSH installiet ist</h3>
    <pre><code class="language-sh"
            >&gt; ssh</code></pre>
    <p>
        Falls <code>ssh</code> korrekt installiert wurde solltest du eine
        <strong>usage</strong>-Message bekommen.
    </p>
    <pre><code class="language-sh"
            >usage: ssh [-46AaCfGgKkMNnqsTtVvXxYy] [-B bind_interface] [-b bind_address]
               [-c cipher_spec] [-D [bind_address:]port] [-E log_file]
               [-e escape_char] [-F configfile] [-I pkcs11] [-i identity_file]
               [-J destination] [-L address] [-l login_name] [-m mac_spec]
               [-O ctl_cmd] [-o option] [-P tag] [-p port] [-R address]
               [-S ctl_path] [-W host:port] [-w local_tun[:remote_tun]]
               destination [command [argument ...]]
           ssh [-Q query_option]</code></pre>
    <h1 id="ssh">SSH</h1>
    <p>
        Ist jetzt <code>ssh</code> erfolgreich installiert kannst du mit dem
        folgenden Befehl auf die <strong>Rechnerhalle</strong> verbinden.
    </p>
    <p>
        Allerdings musst du hierbei immer noch euer <strong>Passwort</strong> eingeben.
    </p>
    <h3 id="auf-die-rechnerhalle-verbinden">Auf die Rechnerhalle verbinden</h3>
    <pre><code class="language-sh"
            >&gt; ssh &lt;ito-username&gt;@lxhalle.in.tum.de
# Example:
&gt; ssh muster@lxhalle.in.tum.de</code></pre>
    <h3 id="rechnerhalle-verlassen">Rechnerhalle verlassen</h3>
    <ol>
        <li>Terminal / Fenster Schließen</li>
        <li><code>exit</code>-Befehl ausführen</li>
    </ol>
    <pre><code
            >&gt; exit</code></pre>
    <h1 id="ssh-ohne-passwort">SSH ohne Passwort</h1>
    <h3 id="warum-sollte-man-einen-ssh-schlüssel-verwenden">
        Warum sollte man einen SSH-Schlüssel verwenden?
    </h3>
    <p>
        Wie du wahrscheinlich schon bemerkt hast, muss du jedes Mal dein <strong
            >Passwort</strong
        >
        eingeben, wenn du versuchst dich, per <code>ssh</code> auf die
        Rechnerhalle zu verbinden. Das kann irgendwann nervig werden, vor allem
        wenn man mehrere Verbindungen zu dem Server gleichzeitig hat.
    </p>
    <p>
        Hierfür gibt ein eine praktische Lösung. Man kann sich ein <strong
            >SSH-Key-Paar</strong
        >
        erstellen, wovon man den <strong>Öffentlichen Schlüssel</strong> an die Rechnerhalle
        schickt.
    </p>
    <p>
        Verbindest du dich nun auf die Rechnerhalle wird jedes Mal dein <strong
            >lokaler, geheimer Schlüssel</strong
        >
        mit dem <strong>öffentlichen Schlüssel auf der Rechnerhalle</strong> abgeglichen.
    </p>
    <p>
        Wenn alles stimmt, kannst du dich sofort verbinden, <strong
            >ohne dein Passwort eingeben zu müssen</strong
        >.
    </p>
    <p>
        Falls du mehr dazu lesen willst is <a
            href="https://www.ssh.com/academy/ssh/public-key-authentication"
            >hier</a
        > ein informativer Link.
    </p>
    <h3 id="ein-ssh-schlüssel-paar-erstellen">
        Ein SSH-Schlüssel-Paar erstellen
    </h3>
    <blockquote>
        <p>
            <strong>Hinweise</strong>: Alle folgenden Befehle müssen auf eurem
            <strong>eigenen Computer</strong>
            ausgeführt werden, <strong>NICHT auf der Rechnerhalle</strong>. Ihr
            könnt die rechneralle mit <code>exit</code> verlassen
        </p>
    </blockquote>
    <p><strong>1. SSH-Schlüssel-Paar erstellen</strong></p>
    <pre><code class="language-sh"
            >&gt; ssh-keygen -t ed25519</code></pre>
    <p>
        <strong
            >2. Dateinamen unverändert lassen (<code>&lt;Enter&gt;</code> drücken)</strong
        >
    </p>
    <pre><code class="language-sh"
            >Generating public/private ed25519 key pair.
Enter file in which to save the key (path/to/home/.ssh/id_ed25519):  # &lt;Enter&gt;</code></pre>
    <p><strong>3. Kein Passwort eingeben</strong></p>
    <p>
        Im nächsten Schritt werdet ihr nach einem <strong>Passwort</strong>
        gefragt. Hier müsst ihr kein Passwort eingeben, sondern einfach nur
        <code>&lt;Enter&gt;</code>. Solltet ihr doch ein Passwort eingeben müsst
        ihr dieses Passwort eingeben, jedes Mal wenn ihr den
        <strong>SSH-Schlüssel</strong> verwendet.
    </p>
    <pre><code class="language-sh"
            ># Hier kein Passwort eingeben, nur &lt;Enter&gt; drücken
Enter passphrase (empty for no passphrase):  # &lt;Enter&gt;
Enter same passphrase again:                 # &lt;Enter&gt;</code></pre>
    <p><strong>4. Geheimer und öffnetlicher Schlüssel</strong></p>
    <p>
        Falls ihr den Schritten korrekt gefolgt seid, solltet ihr in <code
            >~/.ssh</code
        > zwei neue Dateien finden.
    </p>
    <pre><code class="language-sh"
            >&gt; ls -l ~/.ssh
-rw------- 1 user user  411 13. Jan 13:05 id_ed25519        # geheimer Schlüssel
-rw-r--r-- 1 user user  102 13. Jan 13:05 id_ed25519.pub    # öffentlicher Schlüssel</code></pre>
    <h3 id="öffentlichen-schlüssel-an-die-rechnerhalle-schicken">
        Öffentlichen Schlüssel an die Rechnerhalle schicken
    </h3>
    <pre><code class="language-sh"
            >&gt; ssh-copy-id -i ~/.ssh/id_ed25519.pub &lt;ito-username&gt;@lxhalle.in.tum.de 
# Example: ssh-copy-id -i ~/.ssh/id_ed25519.pub muster@lxhalle.in.tum.de</code></pre>
    <h3 id="auf-die-rechnerhalle-zugreifen">Auf die Rechnerhalle zugreifen</h3>
    <p>
        Falls allen Schritten erfolgreich gefolgt wurden, kannst du jetzt mit
        dem selben Befehl wie vorher auf die Rechnerhalle zu greifen. Jetzt aber
        ohne ein Passwort einzugeben.
    </p>
    <pre><code class="language-sh"
            >&gt; ssh &lt;ito-username&gt;@lxhalle.in.tum.de
# Example: ssh muster@lxhalle.in.tum.de</code></pre>
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
    code {
        white-space: pre-line;
    }
</style>

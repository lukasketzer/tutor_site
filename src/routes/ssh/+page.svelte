<script>
    import SSH from "$lib/ssh/SSH.svelte";
    import Header from "$lib/Header.svelte";
    import Navbar from "$lib/Navbar.svelte";
    import Links from "$lib/Links.svelte";
    import Seo from "$lib/Seo.svelte";
</script>

<Seo
    title="SSH-Anleitung für die Rechnerhalle (lxhalle) der TUM"
    description="Schritt-für-Schritt-Anleitung: SSH unter Windows (WSL), macOS und Linux einrichten, per SSH-Schlüssel ohne Passwort auf die Rechnerhalle verbinden und eine SSH-Config anlegen."
    path="ssh"
    type="article"
    jsonld={{
        "@context": "https://schema.org",
        "@type": "TechArticle",
        headline: "SSH-Anleitung für die Rechnerhalle der TUM",
        inLanguage: "de",
        url: "https://home.cit.tum.de/~ketz/ssh",
        author: { "@type": "Person", name: "Lukas Ketzer" },
    }}
/>

<div class="container">
    <Header name={"SSH Guide"} heading={false} />
    <Links
        email={"lukas.a.ketzer@tum.de"}
        github_link={"https://github.com/lukasketzer"}
        zulip={"https://zulip.in.tum.de/#narrow/dm/11498-Lukas-Ketzer"}
        zulip_name={"Lukas Ketzer"}
    />
    <Navbar is_active={2} />

    <SSH />
</div>

<style>
    .container {
        margin-top: 2rem;
    }
</style>

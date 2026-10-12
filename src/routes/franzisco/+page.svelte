<script>
    import Entries from "$lib/franzisco/Entries.svelte";
    import Header from "$lib/Header.svelte";
    import Navbar from "$lib/Navbar.svelte";
    import Links from "$lib/Links.svelte";
    import Seo from "$lib/Seo.svelte";
</script>

<Seo
    title="GRA Tutorium SS24 – Franzisco Schmidt | Grundlagen: Rechnerarchitektur TUM"
    description="Folien und nützliche Links aus dem Tutorium Grundlagen: Rechnerarchitektur (GRA) an der TUM im Sommersemester 2024 bei Franzisco Schmidt."
    path="franzisco"
/>

<div class="container">
    <Header name={"Franzisco Schmidt"} />
    <Links
        email={""}
        github_link={""}
        zulip={"https://zulip.in.tum.de/#narrow/dm/9310-Franzisco-David-Schmidt"}
        zulip_name={"Franzisco David Schmidt"}
    />

    <Navbar is_active={1} />

    <Entries />
</div>

<script>
    import Entries from "$lib/franzisco/Entries.svelte";
    import Header from "$lib/Header.svelte";
    import Navbar from "$lib/Navbar.svelte";
    import Links from "$lib/Links.svelte";
</script>

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

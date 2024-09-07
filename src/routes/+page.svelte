<script>
    import SSH from "$lib/ssh/SSH.svelte";
    import Header from "$lib/Header.svelte";
    import Navbar from "$lib/Navbar.svelte";
    import Links from "$lib/Links.svelte";
</script>

<svelte:head>
    <title>SSH Guide</title>
</svelte:head>

<div class="container">
    <Header name={"SSH Guide"} />
    <!-- <Links
        email={"lukas.a.ketzer@tum.de"}
        github_link={"https://github.com/lukasketzer"}
        zulip={"https://zulip.in.tum.de/#narrow/dm/11498-Lukas-Ketzer"}
        zulip_name={"Lukas Ketzer"}
    /> -->
    <!-- <Navbar is_active={2} /> -->

    <SSH />
</div>

<style>
    .container {
        margin-top: 2rem;
    }
</style>

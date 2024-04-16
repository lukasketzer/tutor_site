<script>
    import SSH from "$lib/ssh/SSH.svelte";
    import Header from "$lib/Header.svelte";
    import Navbar from "$lib/Navbar.svelte";
</script>

<svelte:head>
    <title>SSH Guide</title>
</svelte:head>

<div class="container">
    <Header name={"SSH Guide"} />

    <Navbar is_active={2} />

    <SSH />
</div>

<style>
    .container {
        margin-top: 2rem;
    }
</style>

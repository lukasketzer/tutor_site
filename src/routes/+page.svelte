<script>
    import Entries from "$lib/Entries.svelte";
    import SSH from "$lib/ssh/SSH.svelte";
    let ssh = false;
</script>

<svelte:head>
    <title>GRA SS24</title>
    <link
        rel="stylesheet"
        href="https://cdnjs.cloudflare.com/ajax/libs/github-markdown-css/5.5.1/github-markdown-dark.min.css"
        integrity="sha512-MmL2FuLmm/UH05Ah4JiJwA+G7OCceZDpzGHWqsju4Espzq+9nwQJdQVMNZPd1FNK2H3qDYXdET7HNG7Qm93FEg=="
        crossorigin="anonymous"
        referrerpolicy="no-referrer"
    />


</svelte:head>

<div class="container">
    <div class="header">
        <div>
            <h1 class="title is-1 is-size-3-mobile" style="text-align: center;">
                Grundlagen: Rechenarchitektur
            </h1>
            <h1
                class="subtitle is-3 is-size-5-mobile"
                style="text-align: center;"
            >
                Sommersemester 2024 | Lukas Ketzer
            </h1>
        </div>

        <div class="links">
            <a href="https://github.com/lukasketzer" class="navbar-item">
                <span class="icon-text">
                    <span class="icon">
                        <i class="bi bi-github"></i>
                    </span>
                    Github
                </span>
            </a>
            <a href="mailto:lukas.a.ketzer@tum.de" class="navbar-item">
                <span class="icon-text">
                    <span class="icon">
                        <i class="bi bi-envelope"></i>
                    </span>
                    lukas.a.ketzer@tum.de
                </span>
            </a>
            <div>
                <p class="navbar-item">Zulip: Lukas Ketzer</p>
            </div>
        </div>
    </div>

    <div class="tabs is-centered is-boxed">
        <ul>
            <li class=""><button on:click={() => (ssh = false)}><a href="">Folien</a></button></li>
            <li class=""><button on:click={() => (ssh = true)}><a href="">SSH Guide</a></button></li>
        </ul>
    </div>

    {#if !ssh}
        <div>
            <Entries />
        </div>
    {:else}
        <div>
            <h1 class="title is-2">
                <span><a href="#"> # </a></span>SSH Guide
            </h1>
            <SSH />
        </div>
    {/if}
</div>

<style>
    .links {
        display: flex;
        justify-content: center;
        align-self: center;
        flex-direction: row;
        flex-wrap: wrap;
    }
    .icon {
        padding-bottom: 3px;
    }
    .header {
        margin-top: 5em;
        margin-bottom: 5em;
    }
    .tabs {
        margin-bottom: 5rem;
    }
</style>

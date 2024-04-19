<script>
    export let email;
    export let github_link;
    export let zulip;
</script>

<div class="links">
    <a href={github_link} class="navbar-item">
        <span class="icon-text">
            <span class="icon">
                <i class="bi bi-github"></i>
            </span>
            Github
        </span>
    </a>
    <a href="mailto:{email}" class="navbar-item">
        <span class="icon-text">
            <span class="icon">
                <i class="bi bi-envelope"></i>
            </span>
            {email}
        </span>
    </a>
    <div>
        <p class="navbar-item">Zulip: {zulip}</p>
    </div>
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
</style>
